#include<iostream>
#include<vector>
#include<string>
#include<stdio.h>

#define max 10

class link1;
class field;

        

class graph;
class node
{
        std::vector<field> fp;
        std::vector<link1> ln;
	int id;
        public:
        void add_field(std::string name,std::string type);
      	void display();
 
        void insert_values();
	//void change_id(int);
        node();
	void display_id();
        friend class graph;
	friend class link1;
	template<typename T>
	void update_node(std::string,T);
};

class field
{
	std::string name;
	void *f;
	std::string type;
	public:
	field(void *temp=0,std::string n="",std::string t="");
	friend void node::insert_values();
	friend class graph;	
	friend void node::display();
	template<typename T>
	friend void node::update_node(std::string,T);
};


	
	

class link1
{
	node *link1_t;
	std::string name;
	friend class graph;
	public:
	link1(node *x=0,std::string y="");	
};

void * create_int();
void * create_string();
void * create_float();



class graph
{
	node *head;
	int count;	
	int ref_count;
	std::string name;
	//FILE *file;	
public:
	graph(std::string);
	void insert_node(node *temp);
	
	void add_relation(node *,node *,std::string);
	void traversal();
	void traversal_second(node *,bool visited[],int mat[][max]);
	template <typename T>	
	node * search(std::string field_name,T value);
	template <typename T>
	node * search_second(node *temp,bool visited[],std::string field_name,T value);	
	template<typename T,typename X>
	void update_node(std::string field_name,T value1,std::string new_field,X value2);
};


template <typename T>
node * graph::search_second(node * temp,bool visited[],std::string field_name,T value)
{
	 	visited[temp->id]=1;
             	std::vector<link1>::iterator i=temp->ln.begin();
		node* res=0;
                while(i!=temp->ln.end())
                {
                        if(!visited[i->link1_t->id])
                        {
                                
                		std::vector<field>::iterator it=i->link1_t->fp.begin();
				while(it!=i->link1_t->fp.end())
				{
					if(it->name==field_name)
					{
						if(it->type=="int")
						{	
							if(*(int *)it->f==value)
							{
								res= i->link1_t;
								return res;
						
							}
						}	
					#if END
						else if(it->type=="string")
                                                {
						       if(*(std::string *)(it->f)==value)
                                                        {
                                                                res= i->link1_t;
                                                                return res;
                                                        }
						}
						#endif
						else if(it->type=="float")
                                                {
						        if(*(float *)it->f==value)
                                                        {
                                                                res= i->link1_t;
                                                                return res;
                                                        }
						}
						
						
					}
				it++;
				}
               
                                res=search_second(i->link1_t,visited,field_name,value);
                        }
                i++;
                }
		
				return res;
                                
}

template <typename T>
node * graph::search(std::string field_name,T value)
{
	bool *visited=new bool[count];
        node *temp=head;
        for(int i=0;i<=count;++i)
        {
                visited[i]=0;
        }

       return  search_second(temp,visited,field_name,value);
}
template<typename X>
void node::update_node(std::string new_field,X value2)
{
	std::vector<field>::iterator i=fp.begin();
	while(i!=fp.end())
	{
		if(i->name==new_field)
		{
			if(i->type=="int")
				*(int *)i->f=value2;
			/*else if(i->type=="string")
				*(std::string *)i->f=value2;*/
			else if(i->type=="float")
				*(float *)i->f=value2;
		}
		i++;
	}
}
