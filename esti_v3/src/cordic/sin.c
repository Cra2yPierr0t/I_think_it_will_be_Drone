#include<stdio.h>
int main(){
    double x = 30;

    double theta[18] = {45, 26.56505118, 14.03624347, 7.125016349, 3.576334375, 1.789910608, 0.89517371, 0.447614171, 0.2238105, 0.111905677, 0.055952892, 0.027976453, 0.013988227, 0.006994114, 0.003497057, 0.001748528, 0.000874264, 0.000437132};
    double vec = 1.646760258;
    int sign_table[18];
    double buffer;

    x *= 1073741824;  
    vec *= 1073741824;  
    for(int i=0; i < 18; i++){
        theta[i] *= 1073741824;  
        printf("%lx\n", (long long int)theta[i]);
    }


    sign_table[0] = 1;
    buffer = theta[0] - x;
    for(int i=1; i<18; i++){        //符号のテーブル作成
        printf("%lx\n", (long long int)buffer);
        if(buffer > 0){
            sign_table[i] = -1;
        }else if(buffer <= 0){
            sign_table[i] = 1;
        }
        if(sign_table[i] == -1){
            buffer = buffer - theta[i];
        } else if(sign_table[i] == 1){
            buffer = buffer + theta[i];
        }
    }

    for(int i=0; i < 18; i++){
        printf("%d\n", sign_table[i]);
    }

    double x1 = 1;
    double x2;
    double y1 = 1;
    double y2;
    double i2 = 2;

    double vec2 = 1.646760258;

    x1 *= 8192;
    y1 *= 8192;
    vec2 *= 8192;

    for(int i=1; i<18; i++){
        if(sign_table[i] == -1){
            x2 = x1 + (y1/i2);
            y2 = y1 - (x1/i2);
        } else if(sign_table[i] == 1){
            x2 = x1 - (y1/i2);
            y2 = y1 + (x1/i2);
        }
        printf("x2 = %lf ", x2);
        printf("y2 = %lf\n", y2);
        i2 = 2 * i2;
        x1 = x2;
        y1 = y2;
    }
    printf("sinx = %lf\n", y2/vec2);
    printf("cosx = %lf\n", x2/vec2);


    return 0;
}
