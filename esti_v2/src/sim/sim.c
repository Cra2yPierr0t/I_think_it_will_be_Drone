#include<stdio.h>
#include<math.h>
#include<unistd.h>

int main(){
    double x0 = 0;
    double x1 = 0;
    double v0 = 1;
    double v1 = 0;
    double a0 = 0;
    double a1 = 0;

    printf("\n");
    for(int i = 0; i < 10000; i++){
        x1 = x0 - 0.5*sin(i * 0.01)*0.01*0.01 + v0 * 0.01;
        v1 = v0 - sin(i * 0.01)*0.01;
        x0 = x1;
        v0 = v1;
        //printf("%lf\n", x1);
        if(-2 <= x1 && x1 < -0.5) {
            printf("#---\n");
        } else if(-0.5 <= x1 && x1 < 0) {
            printf("-#--\n");
        } else if(0 <= x1 && x1 < 0.5) {
            printf("--#-\n");
        } else if(0.5 <= x1 && x1 < 2) {
            printf("---#\n");
        }
        usleep(1000);
    }
    return 0;
}
