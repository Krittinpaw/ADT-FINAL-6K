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

int main() {
    struct record *root = NULL;

    // 1. ทดสอบการเพิ่มข้อมูล (Insert)
    // สร้างต้นไม้หน้าตาแบบนี้:
    //         50
    //       /    \
    //     30      70
    //    /  \    /  \
    //  20   40  60   80
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // 2. ทดสอบการแสดงผล (Traversals)
    cout << "--- Tree Traversals ---" << endl;
    cout << "Inorder (Left -> Root -> Right): ";
    printinoreder(root);
    cout << endl;

    cout << "Preorder (Root -> Left -> Right): ";
    printpreorder(root);
    cout << endl;

    cout << "Postorder (Left -> Right -> Root): ";
    printpostorder(root);
    cout << endl;

    // 3. ทดสอบหาค่าน้อยสุดและมากสุด
    cout << "\n--- Min / Max ---" << endl;
    struct record *minNode = findmin(root);
    struct record *maxNode = findmax(root);
    if (minNode != NULL) cout << "Minimum value is: " << minNode->value << endl;
    if (maxNode != NULL) cout << "Maximum value is: " << maxNode->value << endl;

    // 4. ทดสอบการลบโหนด (Delete)
    cout << "\n--- Deletion Tests ---" << endl;
    
    // กรณีที่ 1: ลบ Leaf node (ไม่มีลูก)
    cout << "Deleting 20 (Leaf node)..." << endl;
    root = Delete(20, root);
    cout << "Inorder after delete 20: ";
    printinoreder(root);
    cout << endl;

    // กรณีที่ 2: ลบโหนดที่มีลูก 2 ข้าง (เช่น Root โหนด 50)
    cout << "Deleting 50 (Node with 2 children)..." << endl;
    root = Delete(50, root);
    cout << "Inorder after delete 50: ";
    printinoreder(root);
    cout << endl;

    return 0;
}