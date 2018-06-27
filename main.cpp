#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
using namespace std;
struct item
{
	int cardno,pid;
	int quantity,total_cost;
	item *next;
};
#define newnode (item *)malloc(sizeof(item))
int priority(int pid)
{
	return (pid/100)%10;
}
void enqueue_pre(item **left_pre,int cardno,int pid,int quantity,int total_cost)
{
    item *newitem=newnode;
		newitem->cardno=cardno;
		newitem->pid=pid;
		newitem->quantity=quantity;
		newitem->total_cost=total_cost;
		newitem->next=NULL;
	if((*left_pre)==NULL)
	{
       *left_pre=newitem;
	}

	else
    {
        if(priority(newitem->cardno)>priority((*left_pre)->cardno))
        {
            newitem->next=*left_pre;
            *left_pre=newitem;
        }

        else
        {
            item *p,*q;
            p=*left_pre;
            q=*left_pre;
            while(p!=NULL)
            {
                if(priority(newitem->cardno)<=priority(p->cardno))
                {
                    q=p;
                    p=p->next;
                }
                else
                    break;
            }
            q->next=newitem;
            newitem->next=p;
        }
    }

}
void enqueue_avail(item **left_avail,int cardno,int pid,int quantity,int total_cost)
{
	if(*left_avail==NULL)
	{
		*left_avail=newnode;
		(*left_avail)->cardno=cardno;
		(*left_avail)->pid=pid;
		(*left_avail)->quantity=quantity;
		(*left_avail)->total_cost=total_cost;
		(*left_avail)->next=NULL;
	}
	else
	{
		item *newitem=newnode;
		newitem->cardno=cardno;
		newitem->pid=pid;
		newitem->quantity=quantity;
		newitem->total_cost=total_cost;

		newitem->next=NULL;
		item *p=*left_avail;
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=newitem;
	}
}
struct preorder_data
{
    int id;
    string name;
    int quantity;
    int cost;
    preorder_data *next;
};
struct available_data
{
    int id;
    string name;
    int quantity;
    int cost;
    available_data *next;
};


int main()
{
    struct preorder_data *plist = NULL;
    struct preorder_data *q = NULL;
    ifstream pdata;
    pdata.open("prebooking_data.csv");
    struct available_data *alist = NULL;
    struct available_data *qe = NULL;
    ifstream adata;
    adata.open("availability_data.csv");
    while(pdata.good())
    {
        string iid;
        string name;
        string iquantity;
        string icost;
        getline(pdata,iid,',');
        getline(pdata,name,',');
        getline(pdata,iquantity,',');
        getline(pdata,icost,'\n');
        stringstream geek1(iid);
        int id = 0;
        geek1>>id;
        stringstream geek2(iquantity);
        int quantity = 0;
        geek2>>quantity;
        stringstream geek3(icost);
        int cost = 0;
        geek3>>cost;
        //cout<<id<<" "<<name<<" "<<quantity<<" "<<cost<<endl;
        struct preorder_data *pl = new preorder_data;
        pl->id=id;
        pl->name=name;
        pl->quantity=quantity;
        pl->cost=cost;
        pl->next=NULL;
        if(plist==NULL)
        {
            //plist = new preorder_data;
            plist=pl;
        }
        else
        {
            q=plist;
            while(q->next!=NULL)
            {
                q=q->next;
            }
            q->next=pl;
        }
    }
    while(adata.good())
    {
        string aiid;
        string aname;
        string aiquantity;
        string aicost;
        getline(adata,aiid,',');
        getline(adata,aname,',');
        getline(adata,aiquantity,',');
        getline(adata,aicost,'\n');
        stringstream geek4(aiid);
        int aid = 0;
        geek4>>aid;
        stringstream geek5(aiquantity);
        int aquantity = 0;
        geek5>>aquantity;
        stringstream geek6(aicost);
        int acost = 0;
        geek6>>acost;
        //cout<<id<<" "<<name<<" "<<quantity<<" "<<cost<<endl;
        struct available_data *pll = new available_data;
        pll->id=aid;
        pll->name=aname;
        pll->quantity=aquantity;
        pll->cost=acost;
        pll->next=NULL;
        if(alist==NULL)
        {
            //plist = new preorder_data;
            alist=pll;
        }
        else
        {
            qe=alist;
            while(qe->next!=NULL)
            {
                qe=qe->next;
            }
            qe->next=pll;
        }
    }

    item *left_pre=NULL;
	item *left_avail=NULL;


    int flag=1;
    int x;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"                         SHIPPING RECOMMENDER       "<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"      CARD                 PRIORITY    "<<endl;
    cout<<"      Platinum                 1    "<<endl;
    cout<<"      Gold                     2    "<<endl;
    cout<<"      Silver                   3    "<<endl;
    cout<<"      New customer             4    "<<endl;
    cout<<"-------------------------------------------------------------------"<<endl<<endl;

    while(flag==1)
    {
        cout<<endl<<endl<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<"1) Order request"<<endl;
        cout<<"2) view stock"<<endl;
        cout<<"3) Pre - Booking list"<<endl;
        cout<<"4) Normal Order list"<<endl;
        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<" Enter choice        ";
        cin>>x;
        cout<<"-------------------------------------------------------------------"<<endl;
        cout<<endl;

        switch(x)
        {
        case 1:
            {
                cout<<"1) Pre-Booking products"<<endl;
                cout<<"2) Normal products"<<endl;
                cout<<"-------------------------------------------------------------------"<<endl;
                cout<<"enter choice     ";
                int pn=3;
                cin>>pn;
                switch(pn)
                {
                case 1:
                    {
                       cout<<endl;
                       int count=1;
                       preorder_data *p=plist;
                       while(p->next!=NULL)
                       {
                            cout<<count<<")     Product_ID: "<<p->id;
                            cout<<"     "<<p->name;
                            cout<<"         cost: "<<p->cost<<endl;
                            p=p->next;
                            count++;
                        }
                        cout<<"-------------------------------------------------------------------"<<endl;
                        cout<<endl;
                       cout<<"enter PID to place order      ";
                       int pid;
                       cin>>pid;
                       cout<<"enter quantity        ";
                       int qty;
                       cin>>qty;
                       cout<<"enter customer Card number        ";
                       int cardno;
                       cin>>cardno;
                       cout<<"-------------------------------------------------------------------"<<endl;
                       preorder_data *pq=plist;
                       while(pq->id!=pid)
                       {
                           pq=pq->next;
                       }
                       int cost=pq->cost;
                       int tcost=qty*cost;
                       enqueue_pre(&left_pre,cardno,pid,qty,tcost);
                        break;
                    }

                    case 2:
                        {
                           cout<<endl;
                           int count=1;
                           available_data *p=alist;
                           while(p->next!=NULL)
                           {
                                cout<<count<<")         Product_ID: "<<p->id;
                                cout<<"         "<<p->name;
                                cout<<"     available quantity: "<<p->quantity;
                                cout<<"     cost: "<<p->cost<<endl;
                                p=p->next;
                                count++;
                           }
                           cout<<"-------------------------------------------------------------------"<<endl;

                           cout<<"enter PID to place order      ";
                           int pid;
                           cin>>pid;
                           cout<<"enter quantity        ";
                           int qty;
                           cin>>qty;
                           cout<<"enter customer Card number or 0 if customer do not have a card     ";
                           int cardno;
                           cin>>cardno;
                           cout<<"-------------------------------------------------------------------"<<endl;
                           available_data *pw=alist;
                           while(pw->id!=pid)
                           {
                               pw=pw->next;
                           }
                           int cost=pw->cost;
                           int tcost=qty*cost;
                           if(qty<=pw->quantity)
                           {
                               enqueue_avail(&left_avail,cardno,pid,qty,tcost);
                               pw->quantity-=qty;

                           }
                           else
                                cout<<"quantity greater than available quantity"<<endl;
                           break;
                        }

                        default:
                        {
                            cout<<"invalid choice"<<endl;
                            break;
                        }
                }
                break;
            }

                    case 2:
                        {
                            cout<<"1) Pre-Booking products"<<endl;
                            cout<<"2) Normal products"<<endl;
                            cout<<"-------------------------------------------------------------------"<<endl;
                            cout<<"enter choice     ";
                            int pn=3;
                            cin>>pn;
                            cout<<"-------------------------------------------------------------------"<<endl;
                            switch(pn)
                            {
                            case 1:
                                {
                                   int count=1;
                                    preorder_data *p=plist;
                                    while(p->next!=NULL)
                                      {
                                        cout<<count<<")         Product_ID: "<<p->id;
                                        cout<<"         "<<p->name;
                                        cout<<"         available quantity: "<<p->quantity;
                                        cout<<"         cost: "<<p->cost<<endl;
                                        p=p->next;
                                        count++;
                                      }
                                      cout<<"-------------------------------------------------------------------"<<endl;
                                      break;
                                }



                            case 2:
                                {
                                    cout<<endl;
                                    int count=1;
                                    available_data *p=alist;
                                    while(p->next!=NULL)
                                    {
                                         cout<<count<<")         Product_ID: "<<p->id;
                                         cout<<"      "<<p->name;
                                         cout<<"        available quantity: "<<p->quantity;
                                         cout<<"        cost: "<<p->cost<<endl;
                                         p=p->next;
                                         count++;
                                    }
                                    cout<<"-------------------------------------------------------------------"<<endl;
                                    break;
                                }
                            default:
                                {
                                    cout<<"invalid choice"<<endl;
                                    cout<<"-------------------------------------------------------------------"<<endl;
                                    break;
                                }
                            }
                            break;


                        }

                            case 3:
                                {

                                    item *ql=left_pre;
                                    while(ql!=NULL)
                                    {

                                        cout<<"Product_ID: "<<ql->pid;
                                        cout<<"     quantity: "<<ql->quantity;
                                        cout<<"     card no: "<<ql->cardno<<endl;
                                        ql=ql->next;
                                    }
                                    cout<<"-------------------------------------------------------------------"<<endl;
                                    break;
                                }

                            case 4:
                                {
                                    item *ql=left_avail;
                                    while(ql!=NULL)
                                    {
                                        cout<<"Product_ID: "<<ql->pid;
                                        cout<<"         quantity: "<<ql->quantity;
                                        cout<<"         card no: "<<ql->cardno<<endl;
                                        ql=ql->next;
                                    }
                                    cout<<"-------------------------------------------------------------------"<<endl;
                                    break;
                                }

                            default:
                                {
                                    cout<<"invalid choice"<<endl;
                                    cout<<"-------------------------------------------------------------------"<<endl;
                                    break;
                                }
        }

    }
    return 0;
}
