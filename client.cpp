#include"graph.h"
using namespace std;
#define END 0
int main()
{
	int choice;
	string dbname;
	bool flag=1;
	
	cout<<"Enter name of database"<<endl;
	cin>>dbname;
	graph *g=new graph(dbname);
	
	node *n;
	node*temp;
	node *temp1;
	string rela;
	float val2;
	string field,type;
	string val1;
	int val;
	while(flag)
	{
		cout<<"enter choice\n"<<"1.Add node\n"<<"2.Add relation\n"<<"3.search\n"<<"4.update\n"<<"5.exit\n";
		cin>>choice;
		switch(choice)
		{
			case 1:
				//clrscr();
				int num;
				
				n=new node();
				cout<<"enter number of fields\n";
				cin>>num;
				for(int i=0;i<num;++i)
				{
					cout<<"enter field name and type\n";
					cin>>field >>type;
					n->add_field(field,type);
				}
				n->insert_values();	
				g->insert_node(n);
			break;
			
			case 2:
				cout<<"enter field name for first node\n";
                                cin>>field;
                                cout<<"enter value type\n";
                                cin>>type;
                                if(type=="int")
                                {

                                        cout<<"enter val\n";
                                        cin>>val;
                                        temp=g->search(field,val);
                                        temp->display_id();
                                }
                                /*else if(type=="string")
                                {
                                        
                                        cout<<"enter val\n";
                                        cin>>val1;
                                        temp=g->search(field,val1);
                                        //temp->display_id();
                                }*/
				else if(type=="float")
				{
					cout<<"enter val\n";
                                        cin>>val2;
                                        temp=g->search(field,val2);
                                        temp->display_id();
				}
				cout<<"enter field name for second node\n";
                                cin>>field;
                                cout<<"enter value type\n";
                                cin>>type;
                                if(type=="int")
                                {

                                        cout<<"enter val\n";
                                        cin>>val;
                                        temp1=g->search(field,val);
                                        temp1->display_id();
                                }
                                /*else if(type=="string")
                                {
                                        
                                        cout<<"enter val\n";
                                        cin>>val1;
                                        temp1=g->search(field,val1);
                                        //temp1->display_id();
                                }*/
				else if(type=="float")
                                {
                                        cout<<"enter val\n";
                                        cin>>val2;
                                        temp1=g->search(field,val2);
                                        temp1->display_id();
                                }
				cout<<"enter relation between nodes";
				cin>>rela;
				g->add_relation(temp,temp1,rela);
				



				
			break;
			case 3:
				//clrscr();
				cout<<"enter field name\n";
				cin>>field;
				cout<<"enter value type\n";
				cin>>type;
				if(type=="int")
					{
					
					cout<<"enter val\n";
					cin>>val;
					temp=g->search(field,val);
					//temp->display_id();
					}
				/*else if(type=="string")
				{
					
					cout<<"enter val\n";
					cin>>val1;
					temp=g->search(field,val1);
					temp->display_id();
				}*/
				else if(type=="float")
                                {

                                        cout<<"enter val\n";
                                        cin>>val2;
                                        temp=g->search(field,val2);
                                        //temp->display_id();
                                }
                if(!temp)
                	cout<<"not found"<<endl;
                else 
					temp->display_id();
				break;
			case 4:
				cout<<"enter field name\n";
                                cin>>field;
                                cout<<"enter value type\n";
                                cin>>type;
                                if(type=="int")
                                        {

                                        cout<<"enter val\n";
                                        cin>>val;
                                        temp=g->search(field,val);
                                        temp->display_id();
                                        }
                                /*else if(type=="string")
                                {
                                        
                                        cout<<"enter val\n";
                                        cin>>val1;
                                        temp=g->search(field,val1);
                                        temp->display_id();
                                }*/
                                else if(type=="float")
                                {

                                        cout<<"enter val\n";
                                        cin>>val2;
                                        temp=g->search(field,val2);
                                        temp->display_id();
                                }
				
				cout<<"enter field to be updated\n";
                                cin>>field;
                                cout<<"enter value type\n";
                                cin>>type;
                                if(type=="int")
                                {

                                        cout<<"enter val\n";
                                        cin>>val;
					temp->update_node(field,val);
                                        
                                }                                        
                                /*else if(type=="string")
                                {
                                        
                                        cout<<"enter val\n";
                                        cin>>val1;
                                        temp=g->search(field,val1);
                                        temp->display_id();
                                }*/
				else if(type=="float")
                                {

                                        cout<<"enter val\n";
                                        cin>>val2;
                                        temp->update_node(field,val2);

                                }

                                break;

				
				

				
			case 5:
				//clrscr();
				g->traversal();
				flag=0;
			break;
		
		}		
	}
	/*
	node *n1=new node();
	node *n2=new node();
	node *n3=new node();
	n1->add_field("age","int");
	n1->add_field("name","string");
	n2->add_field("age","int");
        n2->add_field("name","string");
	n3->add_field("age","int");
        n3->add_field("name","string");
	n1->insert_values();
	n2->insert_values();
	n3->insert_values();
	
	g->insert_node(n1);
	g->insert_node(n2);
	g->insert_node(n3);
	g->add_relation(n1,n2,"frnds");
	g->add_relation(n2,n3,"sisters");
	
	node*temp=g->search("age",21);
	temp->display();
	//temp->update_node("name","sanders");	
	temp->display();
	g->traversal();*/
	return 0;
}
