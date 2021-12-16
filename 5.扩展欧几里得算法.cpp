#include <stdio.h>
/*
gcd(a, b) = gcd(b, a % b)
ax + by = gcd(a, b) = 
ax2 + by2 = gcd(b, a % b)
ax + by = bx2 + (a - (a / b) * b)y2
x = x2;y = a - (a / b) * b
*/

int exgcd(int a, int b, int &x, int &y){
    if(b == 0){
        x = 1;
        y = 0;
        return a;
    }
    int r = exgcd(b, a % b, x, y);
    int t = x;
    x = y;
    y = t - (a / b) * y;
    return r;
    
}
int main(){
    int a, b, x, y, r;
    while(~scanf("%d%d", &a, &b)){
        r = exgcd(a, b, x, y);
        printf("x = %d   y = %d    r = %d\n", x, y, r);
        
    }
    
}


