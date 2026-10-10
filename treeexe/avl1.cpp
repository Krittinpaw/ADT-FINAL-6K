#include<iostream>
using namespace std;

struct record{

    int value;
    int height;
    struct record *left;
    struct record *right;
};

int fheigth(struct record *tree){

    if (tree == NULL)
    {
        return -1;
    }else{
        return tree -> height;
    }
    
}

int max(int f1,int f2){

    if (f1 > f2)
    {
        return f1;
    }else if (f2 > f1)
    {
        return f2;
    }else{
        return f1;
    }
    
}

struct record *srr(struct record *k2){

    struct record *k1;
    k1 = k2 -> left;
    k2 -> left = k1 -> right;
    k1 -> right = k2;
    k2 -> height = max(fheigth(k2 -> left),fheigth(k2 -> right)) + 1;
    k1 -> height = max(fheigth(k1 -> left),fheigth(k2 -> right)) + 1;
    return k1;
}

struct record *slr(struct record *k2){

    struct record *k1;
    k1 = k2 -> right;
    k2 -> right = k1 -> left;
    k1 -> left = k2;
    k2 -> height = max(fheigth(k2 -> left),fheigth(k2 -> right)) + 1;
    k1 -> height = max(fheigth(k1 -> left),fheigth(k1 -> right)) + 1;
    return k1;
}

struct record *drl(struct record *k3){

    k3 -> right = srr(k3 -> right);
    return slr(k3);
}

struct record *dlr(struct record *k3){

    k3 -> left = slr(k3 -> left);
    return srr(k3);
}

struct record *insert(int x , struct record *tree){

    if (tree == NULL)
    {
        tree = new struct record;
        tree -> value = x;
        tree -> left = tree -> right = NULL;
        tree -> height = 0;
    }else{

        if (x < tree -> value)
        {
            tree = insert(x,tree -> left);

            if (fheigth(tree -> left) - fheigth(tree -> right) == 2)
            {
                if (x < tree -> left -> value)
                {
                    tree = srr(tree);
                }else{
                    tree = dlr(tree);
                }
                
            }
            
        }else if (tree -> value < x)
        {
            
           tree = insert(x,tree -> right);

           if (fheigth(tree -> right) - fheigth(tree -> left) == 2)
           {

                if (x < tree -> right -> value)
                {
                    tree = slr(tree);
                }else{
                    tree = drl(tree);
                }
                
           }
           
            
        }
        
        
    }

    tree -> height = max(fheigth(tree -> left), fheigth(tree -> right)) + 1;

    return tree;
    
}