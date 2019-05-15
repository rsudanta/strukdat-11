/*
*Author:M Risqullah Sudanta G
*NPM: 140810180066
*Deskripsi: Exercise-02
*Tahun: 2019
*/
#include <iostream>
using namespace std;

struct Simpul
{
	int data;
	Simpul* left;
	Simpul* right;
};
typedef Simpul* pointer;
typedef pointer Tree;

void createSimpul (pointer& pBaru)
{
	pBaru=new Simpul;
	cout << "Insert a number: "; cin >> pBaru->data;
	pBaru->left=NULL;
	pBaru->right=NULL;
}

void insertBST (Tree& Root, pointer pBaru)
{
	if (Root==NULL) 
		Root=pBaru;
	else if (pBaru->data<Root->data)
		insertBST(Root->left,pBaru);
	else if (pBaru->data>=Root->data)
		insertBST(Root->right,pBaru);
	else 
		cout << "Already exists." << endl;
}

void preOrder(Tree Root)
{
	if (Root!=NULL)
	{
		cout << Root->data << " ";
		preOrder(Root->left);
		preOrder(Root->right);
	}
}

void inOrder(Tree Root)
{
	if (Root!=NULL)
	{
		preOrder(Root->left);
		cout << Root->data << " ";
		preOrder(Root->right);
	}
}

void postOrder(Tree Root)
{
	if (Root!=NULL)
	{
		preOrder(Root->left);
		preOrder(Root->right);
		cout << Root->data << " ";
	}
}

int height(Tree Root)
{
	if (Root==NULL)	return 0;
	else
	{
		int lHeight=height(Root->left);
		int rHeight=height(Root->right);
		
		if (lHeight>rHeight) return (lHeight+1);
		else return (rHeight+1);
	}
}

void givenLevel(Tree Root, int level)
{
	if (Root==NULL) return;
	if (level==1) cout << Root->data << " ";
	else if (level>1)
	{
		givenLevel(Root->left,level-1);
		givenLevel(Root->right,level-1);
	}
}

void levelOrder(Tree Root)
{
	int h=height(Root);
	for (int i=1; i<=h; i++)
	{
		cout << i << ": ";
		givenLevel(Root,i);
		cout << endl;
	} 
}

void depthOrder (Tree Root)
{
	int h=height(Root);
	for (int i=1; i<=h; i++)
	{
		cout << i-1 << ": ";
		givenLevel(Root,i);
		cout << endl;
	} 
}

Tree searchFather(Tree Root, int key)
{
	if (Root==0 || Root->data==key) return Root;
	else if (Root->data<key) return searchFather(Root->left,key);
	else return searchFather(Root->right,key);
}

int main()
{
	Tree X=NULL;
	pointer p;
    int menu,numberData,key;
    char pil;
	
    do
    {
		system("clear");
        cout << "Menu: "
             << "\n1. Insert BST"
             << "\n2. Print PreOrder Traversal"
             << "\n3. Print InOrder Traversal"
             << "\n4. Print PostOrder Traversal"
             << "\n5. Print Depth and Node(s)"
             << "\n6. Print Level and Node(s)"
             << "\n7. Print Father and Child(ren)"
             << "\n8. Exit"
			 << "\nOption: ";
        cin >> menu;

        switch(menu)
        {
            case 1: cout << "Number(s) of Data: "; cin >> numberData;
                    for (int i=0; i<numberData; i++)
                    {
                        createSimpul(p);
	                    insertBST(X,p);
                    }
                    break;
            case 2: cout << "Pre Order Traversal: ";
	                preOrder(X);
                    break;
            case 3: cout << "In Order Traversal: ";
	                inOrder(X);
                    break;
            case 4: cout << "Post Order Traversal: ";
	                postOrder(X);
                    break;
			case 5: cout << "Print Depth and Node(s):\n";
					depthOrder(X);
					break;
            case 6: cout << "Print Level and Node(s):\n";
	                levelOrder(X);
                    break;
			case 7: cout << "Insert Father: "; cin >> key;
					preOrder(searchFather(X,key));
					break;
			case 8: return 0;
					break;
            default: cout << "Option is not valid." << endl;
                     break;
        }   
        cout << "Continue? (Y/N) "; cin >> pil;
    } while (pil=='Y' || pil=='y');
}
