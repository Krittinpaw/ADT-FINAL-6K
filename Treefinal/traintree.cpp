#include<iostream>
using namespace std;

struct node{

    int value;
    struct node *left;
    struct node *rigth;
    int heigth;

};

int fheigth(struct node *p){

    if (p == NULL)
    {
        return -1;
    }else{
        return p -> heigth;
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

//srrrigth"ต้นไม้หนักซ้าย (Left-Left Case)" 
//k2 (ประธานบริษัทคนเก่า): ตอนนี้มีลูกน้องฝั่งซ้ายเยอะมากจนองค์กรเสียสมดุล
struct node *srrright(struct node *k2){
    //k1 (รองประธานฝั่งซ้าย): เป็นลูกน้องมือซ้ายของ k2 ที่ผลงานดี ลูกน้องเยอะ
    struct node *k1;//บริษัทสร้างป้ายชื่อตำแหน่ง "ว่าที่ประธานบริษัทคนใหม่" เตรียมไว้
    k1 = k2 -> left;//บอร์ดบริหารชี้เป้าว่า "คุณ k1 (รองประธานฝั่งซ้าย) นี่แหละ คือคนที่จะขึ้นมาเป็นประธานคนใหม่แทน k2"
    k2 -> left = k1 -> rigth;//เนื่องจากเดี๋ยว k1 จะขึ้นเป็นประธาน และ k2 จะถูกเตะไปอยู่ฝั่งขวา... ตำแหน่ง 
    //"ลูกน้องมือขวาของ k1" จะว่างงาน จึงโอนย้ายลูกน้องกลุ่มนี้ไปให้เป็นลูกน้องมือซ้ายของ k2 แทน 
    //(เพราะข้อมูลกลุ่มนี้มีค่ามากกว่า k1 แต่น้อยกว่า k2 เลยต้องอยู่ซ้ายของ k2)
    k1 -> rigth = k2;//ประกาศโปรโมท! k1 ขึ้นเป็นประธานบริษัทอย่างเป็นทางการ และสั่งให้ประธานเก่า k2 ไปรับตำแหน่งรองประธานฝั่งขวาแทน
    k2 -> heigth = max(fheigth(k2 -> left),fheigth(k2 ->rigth) ) + 1;//เมื่อจัดผังองค์กรเสร็จ k2 (ที่ตอนนี้กลายเป็นรองประธานแล้ว) ต้องนับระดับชั้นลูกน้องใต้บังคับบัญชาของตัวเองใหม่ เพื่ออัปเดตแฟ้มประวัติ
    k1 -> heigth = max(fheigth(k1 -> left),fheigth(k1 -> rigth) ) + 1;//k1 ก็ต้องอัปเดตระดับชั้นโครงสร้างของทั้งบริษัทเช่นกัน (สังเกตว่าต้องรอให้ k2 นับประวัติของตัวเองให้เสร็จก่อน k1 ถึงจะสรุปภาพรวมทั้งหมดได้)
    return k1;//ส่งโครงสร้างองค์กรใหม่ให้บอร์ดบริหารรับทราบว่า "ผังใหม่เสร็จแล้วนะ ตอนนี้บริษัทนี้มี k1 เป็นหัวเรือใหญ่!"
}

struct node *srleft(struct node *k2){

    struct node *k1;
    k1 = k2 -> rigth;
    k2 -> rigth = k1 -> left;
    k1 -> left = k2;
    k2 -> heigth = max(fheigth(k2 -> left),fheigth(k2 -> rigth) ) + 1;
    k1 -> heigth = max(fheigth(k1 -> left),fheigth(k1 -> rigth) ) + 1;
    return k1;

}

struct node *dLR(struct node *k3){

    k3 -> left = srleft(k3 -> left);//สั่งให้ลูกน้องฝั่งซ้าย (k3->left) ทำท่า "หมุนซ้าย" ก่อน 1 รอบ เพื่อ ดัด ไอ้ที่หักมุมขวาอยู่ ให้ตกลงมาเป็นเส้นตรง (กลายเป็นทรงซ้าย-ซ้าย /)
    return srrright(k3);//พอต้นไม้ตรงเป็นทรงซ้าย-ซ้ายแล้ว มันก็เข้าทางเรา! เราก็เรียกใช้ท่าไม้ตาย "หมุนขวา" (srrright) ที่ระดับบนสุด (k3) เพื่อดึงมันขึ้นมาสมดุลตรงกลาง
}

struct node *dRL(struct node *k3){

    k3 -> rigth = srrright(k3 -> rigth);
    return srleft(k3);
}

struct node *insert(int x , struct node *tree){

    if (tree == NULL)
    {
        tree =new struct node;
        tree -> value = x;
        tree -> left = tree -> rigth = NULL;
        tree -> heigth = 0;
    }else{

        if (x < tree -> value)
        {
            tree -> left = insert(x,tree -> left);
            if (fheigth(tree -> left) - fheigth(tree -> rigth) == 2)
            {
                if (x < tree -> left -> value)
                {
                    tree = srrright(tree);
                    //ถ้า x < ลูกซ้าย: แปลว่าค่า x มันพุ่งทะลุไปทางซ้ายสุดเป็นเส้นตรง (/) อาการนี้คือ LL Case เราจึงสั่งแก้ด้วยท่า "หมุนขวา" (srrright) รวดเดียวจบ
                }else{
                    tree = dLR(tree);
                    //แปลว่าตอนแรกวิ่งมาซ้าย แต่ดันหักเลี้ยวไปขวา กลายเป็นทรงบูมเมอแรง (<) อาการนี้คือ LR Case
                }
                
            }
            
        }else if (x > tree -> value)
        {
            tree -> rigth = insert(x , tree -> rigth);
            if (fheigth(tree -> rigth) - fheigth(tree -> left) == 2)
            {
                if (x > tree -> rigth -> value)
                {
                    tree = srleft(tree);
                }else{
                    tree = dRL(tree);
                }
                
            }
            
        }
        
        
    }

    tree -> heigth = max(fheigth(tree -> left) , fheigth(tree -> rigth)) + 1;
    return tree;
    
}