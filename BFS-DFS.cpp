
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<chrono>
#include <string>
using namespace std;
struct Node
{
    string label;
    vector<Node*> children;
};
struct Tree
{
    Node* rootNode = nullptr;
    void printNodes(Node* n)
    {
        cout<<n->label<<endl;
        if(n->children.empty()!=true){
            for(auto i : n->children){
                printNodes((i));
            }
        }
    }
    string depthFirstSearch(Node* n, string toFind)
    {
        auto dfstart = chrono::high_resolution_clock::now();
        stack<Node*> open;
        stack<Node*> closed;
        open.push(n);
        Node* curr;
        string res = "Depth First Search: ";
        while(!open.empty())
        {
            curr = open.top();
            closed.push(open.top());
            res = res + "->" + closed.top()->label;
            open.pop();
            for(auto i = curr->children.rbegin(); i != curr->children.rend(); i++)
            {
                open.push(*i);
            }
            if(curr->label==toFind)
            {
                break;
            }
        }
        auto dfend = chrono::high_resolution_clock::now();
        auto dur_dfs = chrono::duration_cast<chrono::nanoseconds>(dfend-dfstart);
        return res + "Time of Execution : DFS = " + to_string(dur_dfs.count());
    }
    string breadthFirstSearch(Node* n, string toFind)
    {
        auto bfstart = chrono::high_resolution_clock::now();
        queue<Node*> open;
        queue<Node*> closed;
        open.push(n);
        Node* curr;
        string res = "Breadth First Search: ";
        while(!open.empty())
        {
            curr = open.front();
            closed.push(open.front());
            res = res + "->" + closed.back()->label;
            open.pop();
            for(auto i = curr->children.begin(); i != curr->children.end(); i++)
            {
                open.push(*i);
            }
            if(curr->label==toFind)
            {
                break;
            }
        }
        auto bfend = chrono::high_resolution_clock::now();
        auto dur_bfs = chrono::duration_cast<chrono::nanoseconds>(bfend-bfstart);
        return res + "Time of Execution : BFS = " + to_string(dur_bfs.count());
    }
};
int main()
{
    Tree t;
    Node a;
    a.label = "Alpha";
    Node b;
    b.label = "Bravo";
    Node c;
    c.label = "Charlie";
    Node d;
    d.label = "Delta";
    Node e;
    e.label = "Echo";
    Node f;
    f.label = "Foxtrot";
    Node g;
    g.label = "Golf";
    Node h;
    h.label = "Hotel";
    Node i;
    i.label = "India";
    Node j;
    j.label = "Juliet";
    Node k;
    k.label = "Kilo";
    Node l;
    l.label = "Lima";
    Node m;
    m.label = "Mike";
    Node n;
    n.label = "November";
    Node o;
    o.label = "Oscar";
    Node* ap = &a;
    Node* bp = &b;
    Node* cp = &c;
    Node* dp = &d;
    Node* ep = &e;
    Node* fp = &f;
    Node* gp = &g;
    Node* hp = &h;
    Node* ip = &i;
    Node* jp = &j;
    Node* kp = &k;
    Node* lp = &l;
    Node* mp = &m;
    Node* np = &n;
    Node* op = &o;
    a.children.push_back(bp);
    a.children.push_back(cp);
    b.children.push_back(dp);
    b.children.push_back(ep);
    c.children.push_back(fp);
    c.children.push_back(gp);
    d.children.push_back(hp);
    d.children.push_back(ip);
    e.children.push_back(jp);
    e.children.push_back(kp);
    f.children.push_back(lp);
    f.children.push_back(mp);
    g.children.push_back(np);
    g.children.push_back(op);
    t.rootNode = ap;
    t.printNodes(ap);
    
    cout<<t.depthFirstSearch(ap, "November")<<endl;
    cout<<t.breadthFirstSearch(ap, "Oscar")<<endl;
    //maine first time aaj suna ki adjacency matrix bolke bhi koi cheez hai
    //baap re
    //nahi bhai
    //mereko dsa nahi aata
    //bhai maaf kar de mai noob hoon yaar jaane de mereko mai kahaan tere saamne coding kar sakta tu kya bol raha hai yaar
    //nahi aata mereko dsa
}
/*
        A
       / \
      /   \
     B     C
    / \   / \
   D   E  F   G
  / \ / \/ \ / \
 H  IJ  KL  MN  O
 DFS
 open=[a], close=[]
 open=[b,c], close=[a]
 open=[d,e,c], close=[a,b]
 open=[h,i,e,c], close=[d,b,a]
 open=[i,e,c], close=[h,d,b,a]
 open=[e,c], close=[i,h,d,b,a]
 open=[j,k,c], close=[e,i,h,d,b,a]
 open=[k,c], close=[j,e,i,h,d,b,a]
 open=[c], close=[k,j,e,i,h,d,b,a]
 open=[f,g], close=[c,k,j,e,i,h,d,b,a]
 open=[l,m,g], close=[f,c,k,j,e,i,h,d,b,a]
 open=[m,g], close=[l,f,c,k,j,e,i,h,d,b,a]
 ----open=[g], close=[m,l,f,c,k,j,e,i,h,d,b,a]
 open=[n,o], close=[g,m,l,f,c,k,j,e,i,h,d,b,a]
 open=[o], close=[n,g,m,l,f,c,k,j,e,i,h,d,b,a]
 open=[], close=[o,n,g,m,l,f,c,k,j,e,i,h,d,b,a]
 BFS
 open=[a], close=[]
 open=[b,c], close=[a]
 open=[c,d,e], close=[b,a]
 open=[d,e,f,g], close=[c,b,a]
 open=[e,f,g,h,i], close=[d,c,b,a]
 open=[f,g,h,i,j,k], close=[e,d,c,b,a]
 open=[g,h,i,j,k,l,m], close=[f,e,d,c,b,a]
 open=[h,i,j,k,l,m,n,o], close=[g,f,e,d,c,b,a]
 open=[i,j,k,l,m,n,o], close=[h,g,f,e,d,c,b,a]
 open=[j,k,l,m,n,o], close=[i,h,g,f,e,d,c,b,a]
 open=[k,l,m,n,o], close=[j,i,h,g,f,e,d,c,b,a]
 open=[l,m,n,o], close=[k,j,i,h,g,f,e,d,c,b,a]
 open=[m,n,o], close=[l,k,j,i,h,g,f,e,d,c,b,a]
 open=[n,o], close=[m,l,k,j,i,h,g,f,e,d,c,b,a]
 ----open=[o], close=[n,m,l,k,j,i,h,g,f,e,d,c,b,a]
 open=[], close=[o,n,m,l,k,j,i,h,g,f,e,d,c,b,a]
*/
