#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node *next;

    node(){
        data=0;
        next = NULL;
    }
};

struct node *start;

void getdata(int n){
    int data=0;
    start = new node();

    cin>>data;
    start->data = data;
    start->next = NULL;

    if(start != NULL){
        struct node *temp = start;
        struct node *newdata;
        for(int i=1;i<n;i++){
            newdata = new node();
            cin>>data;
            newdata->data = data;
            newdata->next = NULL;
            temp->next = newdata;
            temp = temp->next;
        }
    }
    }

    void del_pos(int p,int n){
        if(start != NULL){
            struct node *temp = start;
            struct node *after = start->next;
            if(p == 0){
                start = start->next;
                temp->next = NULL;
                free(temp);
            }
            else if(p == n-1){
                while(after != NULL){
                    after = after->next;
                    temp = temp->next;
                }
                temp->next = NULL;
                free(after);
            }
            else{
                int i=1;
                while(i != p){
                    after = after->next;
                    temp = temp->next;
                    i++;
                }
                after = after->next;
                temp->next = NULL;
                temp->next = after;
            }
        }
    }

    void showdata(){
        if(start!= NULL){
        struct node *temp = start;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        }
    }

int main(){
    int n=0;
    cin>>n;
    getdata(n);
    //showdata();
    int p=0;
    cin>>p;
    del_pos(p,n);
    showdata();
}