#include<iostream>
using namespace std;

struct record{

    int value;
    struct record *left;
    struct record *rigth;
};

struct record *insert(struct record *t , int num){

    if (t == NULL)
    {
        t = new struct record;
        t -> value = num;
        t -> left = NULL;
        t -> rigth = NULL;
    }else{

        if (num < t -> value)
        {
            t -> left = insert(t -> left , num);
        }else if (t -> value < num)
        {
            t -> rigth = insert(t -> rigth , num);
        }
         
    }

    return t;
    

}

struct record *findmin(struct record *tree){
    
    if (tree == NULL)
    {
        return NULL;
    }else{

        if (tree -> left == NULL)
        {
            return tree;
        }else{

            return (findmin(tree -> left));
        }
        
    }
    
}

struct record *findmax(struct record *tree){

    if (tree == NULL)
    {
        return tree;
    }else{

        if (tree -> rigth == NULL)
        {
            return tree;
        }else{

            return(findmax(tree -> rigth));
        }
        
    }
    
}

struct record *Delete(int target , struct record *tree){

    struct record *tmpcell , *child;

    if (tree == NULL)
    {
        cout << "No node";
        return NULL;
    }else{

        if (target < tree -> value)
        {
            tree -> left = Delete(target,tree -> left);
        }else if (tree -> value < target)
        {
            tree -> rigth = Delete(target,tree -> rigth);
        }else if (tree -> left != NULL && tree -> rigth != NULL)
        {
            tmpcell = findmin(tree -> rigth);//เปรียบเสมือนการหาตัวตายตัวแทนมาทดแทนในส่วนทำไมไม่ findmin(tree -> left) เพราะจะผิดกฤของ tree
            tree -> value = tmpcell -> value;//และให้ tree นะตอนนี้ที่เป็นเป้าหมายในการลบของเรา เปลี่ยนค่าเป็น ตัวที่ไปหามา(ตัวจายตัวแทน)
            tree -> rigth = Delete(tree -> value , tree -> rigth);//ตอนนี้ tree กับ tree -> rigth มีค่าเป็นเลขเดียวกัน เราจึงเลือกลบตัวขวาแทน
        }else{

            //นะส่วนตรงนี้คือ basecase เมื่อ recursive ถึงจุดที่มาจากกรณีน้อยกว่าด้านบน
            tmpcell = tree;//ตัวที่จะลบจะถูกส่งมาถึงจุดนี้
            if (tree -> left == NULL)//เชค ถ้าขวาว่าง
            {
                child = tree -> rigth; //node childe ของ ตัวปัจจุบันขะขึ้นมาแทน
            }else if (tree -> rigth == NULL)
            {
                child = tree -> left;//node childe ของ ตัวปัจจุบันขะขึ้นมาแทน
            }

            delete(tmpcell);//ลบ node ปัจจุบัน
            return child;// ส่ง childe node ขึ้นไปต่อ
            
            
        }
        
        
        
    }

    return tree;
    

}

void printinoreder(struct record *tree){

    if (tree != NULL)
    {
        printinoreder(tree -> left);
        cout << tree -> value << " ";
        printinoreder(tree -> rigth);
    }
    
}

void printpreorder(struct record *tree){

    if (tree != NULL)
    {
        cout << tree -> value << " ";
        printpreorder(tree -> left);
        printpreorder(tree -> rigth);
    }
    
}

void printpostorder(struct record *tree){

    if (tree != NULL)
    {
        printpostorder(tree -> left);
        printpostorder(tree -> rigth);
        cout << tree -> value << " ";
    }
    
}