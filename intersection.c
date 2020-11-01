#include <stdio.h> 
#include <stdlib.h> 
struct rect_t{
    float left; 
    float bottom; 
    float right;
    float top;
}; 
typedef struct rect_t rect;  

float max(float f1, float f2){ 
    return (f1 > f2)? f1 : f2; 
}

float min(float f1, float f2){ 
    return (f1 < f2)? f1 : f2;
}

rect intersection(rect r1, rect r2){ 
    rect ans;  
    ans.left = max(r1.left, r2.left); 
    ans.bottom = max(r1.bottom, r2.bottom); 
    ans.right = min(r1.right, r2.right); 
    ans.top = min(r1.top, r2.top);  
    return ans; 
}

int main(){ 
    rect r1, r2;  
    printf("Enter left, bottom, right, top positions for rectangle 1: "); 
    scanf("%f %f %f %f", &r1.left, &r1.bottom, &r1.right, &r1.top); 
    printf("Enter left, bottom, right, top positions for rectangle 2: "); 
    scanf("%f %f %f %f", &r2.left, &r2.bottom, &r2.right, &r2.top); 
    
    rect ans = intersection(r1, r2); 
    printf("r1 and r2 intersect at left %f, bottom %f, right %f, top %f\n", ans.left, ans.bottom, ans.right, ans.top); 
    return 0; 
}
