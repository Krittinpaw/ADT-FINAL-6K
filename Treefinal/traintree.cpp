#include <iostream>
using namespace std;

struct record
{

    int value;
    struct record *left;
    struct record *rigth;
};

struct record *insert(int num, struct record *tree)
{

    if (tree == NULL)
    {
        tree = new struct record;
        tree->value = num;
        tree->left = tree->rigth = NULL;
    }
    else
    {

        if (num < tree->value)
        {
            tree->left = insert(num, tree->left);
        }
        else if (tree->value < num)
        {
            tree->rigth = insert(num, tree->rigth);
        }
    }

    return tree;
}

struct record *findmin(struct record *tree)
{

    if (tree == NULL)
    {
        return NULL;
    }
    else
    {

        if (tree->left == NULL)
        {
            return tree;
        }
        else
        {
            return (findmin(tree->left));
        }
    }
}

struct record *findmax(struct record *tree)
{

    if (tree == NULL)
    {
        return NULL;
    }
    else
    {

        if (tree->rigth == NULL)
        {
            return tree;
        }
        else
        {

            return (findmax(tree->rigth));
        }
    }
}

struct record *deletetree(int target , struct record *tree){

    struct record *tmpcell , *childe;

    if (tree == NULL)
    {
        return NULL;
    }else{

        if (target < tree -> value)
        {
            tree -> left = deletetree(target , tree -> left);
        }else if (tree -> value < target)
        {
            tree -> rigth = deletetree(target , tree -> rigth);
        }else if (tree -> left != NULL && tree -> rigth != NULL)
        {
            
            tmpcell = findmin(tree -> rigth);
            tree -> value = tmpcell -> value;
            tree -> rigth = deletetree(tree -> value , tree -> rigth);
        }else{

            tmpcell = tree;

            if (tree -> left == NULL)
            {
                childe = tree -> rigth;
            }else if (tree -> rigth == NULL)
            {
                childe = tree -> left;
            }

            delete(tmpcell);
            return childe;
            
            
        }
        
        
        
    }

    return tree;
    
}