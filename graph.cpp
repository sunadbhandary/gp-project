#include "graph.h"


#include<cstdlib>
using namespace std;

link1::link1(node *x,string y):link1_t(x),name(y)
{

}
field::field(void *x,string n,string t):f(x),name(n),type(t)
{

}
node::node()
{
	
	
	id=0;
}
void node::display()
{
	vector<field>::iterator i=fp.begin();
	while(i!=fp.end())
	{
		cout<<i->name<<"::";
		if(i->type=="int")
		{
			cout<<*(int*)i->f;
		}
		if(i->type=="string")
                {
                        cout<<*(string*)i->f;
                }
		if(i->type=="float")
                {
                        cout<<*(float*)i->f;
                }
		cout<<endl;
		i++;
	}
}
/*void node::change_id(int t)
{
	id=t;
}*/
void node::add_field(string name,string type)
{
	void *temp;
	if(type=="int")
		temp=create_int();
	else if(type=="float")
		temp=create_float();
	else if(type=="string")
		temp=create_string();
	
	fp.push_back(field(temp,name,type));
}
	





void * create_int()
{
	return new int;
}
void * create_float()
{
        return new float;
}
void * create_string()
{
        return new string;

}

void node::insert_values()
{
	vector<field>::iterator it=fp.begin();
	while(it!=fp.end())
	{
		cout<<"Enter "<<it->name<<"::";
		if(it->type=="int")
		{
			cin>>*(int *)it->f;
			
		}
		else if(it->type=="string")
		{
			cin>>*(string *)it->f;
			
		}
		else if(it->type=="float")
		{
			cin>>*(float *)it->f;
			
		}
		it++;
		
	}
	
		
	
}




graph::graph(string dbname):ref_count(0),count(0)
{
	
	head=new node();
	
	name=dbname;
	const char * c = name.c_str();
	FILE *file=fopen(c,"w+");
	fclose(file);
	
}

void graph::insert_node(node *new_node)
{
	count++;
	new_node->id=count;
	head->ln.push_back(link1(new_node,"head"));
	ref_count++;
	const char * c = name.c_str();
	FILE *file=fopen(c,"w+");
	fwrite(new_node,1,sizeof(new_node),file);
	fclose(file);
	
	
}
void graph::add_relation(node *src,node *dest,string name)
{
        src->ln.push_back(link1(dest,name));
	if(ref_count>1)
	{
	vector<link1>::iterator iter;	
	for( iter = head->ln.begin(); iter != head->ln.end(); ++iter )
		{
    			if( iter->link1_t == dest )
    			{
        			head->ln.erase( iter );
        			ref_count--;
        			break;
    			}
		}
	}
}

void graph::traversal()
{
	bool *visited=new bool[count];
	node *temp=head;
	int mat[max][max];
	for(int z=0;z<=count;++z)
	{
		for(int x=0;x<=count;++x)
		{
			mat[z][x]=0;
		}
	}
	for(int i=0;i<=count;++i)
	{
		visited[i]=0;
	}
	traversal_second(temp,visited,mat);
	string m=name+"mat";
	const char * c = m.c_str();
	for(int z=0;z<=count;++z)
        {
                for(int x=0;x<=count;++x)
                {
                       cout<< mat[z][x];
                }
		cout<<endl;
        }
	
	FILE *fp=fopen(c,"w");
	fwrite(&count,1,sizeof(int),fp);
	
	fwrite(mat,1,sizeof(mat),fp);
	fclose(fp);
}

void graph::traversal_second(node *temp,bool visited[],int mat[][max])
{
		visited[temp->id]=1;
		vector<link1>::iterator i=temp->ln.begin();
		while(i!=temp->ln.end())
		{
			mat[temp->id][i->link1_t->id]=1;
			if(!visited[i->link1_t->id])
			{
				//cout<<i->link1_t->id;
				traversal_second(i->link1_t,visited,mat);
			}
			i++;
		}
}

												
	
void node::display_id()
{
	cout<<"\nid::"<<id<<endl;
}

/*void graph::construct_graph(string name)
{
	FILE *fp;
	string m=name+"mat";
	const char * c = m.c_str();
	fp=fopen(c,"r");
	int temp;
	fread(&temp,sizeof(temp),1,fp);
	count=temp;
	int mat[size][size];
	fread(&mat,sizeof(mat),1,fp);
	node * nodes[count];
*/	
	
