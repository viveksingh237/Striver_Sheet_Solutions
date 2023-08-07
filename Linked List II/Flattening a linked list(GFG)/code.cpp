//{ Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    
///******Without Using Extra Space ***********
Node *merge(Node *a, Node *b){
    Node *temp = new Node(0);
    Node *res = temp;
    while(a != NULL and b != NULL){
        if(a->data <= b->data){
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else{
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    
    if(a) temp->bottom = a;
    else temp->bottom = b;
    
    return res->bottom;
}
Node *flatten(Node *root)
{
   if(root == nullptr or root->next == nullptr)
   return root;
   
   root->next = flatten(root->next);
   root = merge(root, root->next);
   
   return root;
}

//*********** Using extra Space***********
// Node *flatten(Node *root)
// {
//   vector<int> v;
//   Node *temp1, *temp2;
//   temp1 = root;
//   while(temp1){
//       v.push_back(temp1->data);
//       temp2 = temp1->bottom;
//       while(temp2){
//           v.push_back(temp2->data);
//           temp2 = temp2->bottom;
//       }
//       temp1 = temp1->next;
//   }
//   sort(v.begin(),v.end());
//   //for(auto& x : v) cout<<x<<" ";
   
//   Node *temp3 = new Node(0);
//   Node *temp4 = temp3;
//   for(auto& x : v){
//       Node *temp5 = new Node(x);
//       temp3->bottom = temp5;
//       temp3 = temp3->bottom;
//   }
//   temp3->bottom = NULL;
//   return temp4->bottom;
// }


