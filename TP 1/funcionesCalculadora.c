#include<stdio.h>
float sumar (float x, float y)
{
    float s;
    s=x+y;
    return s;
}
float restar (float x, float y)
{
    float r;
    r=x-y;
    return r;
}
float dividir (float x, float y)
{
    float d;
    d=(float)x/y;
    return d;
}

float multiplicar (float x, float y)
{
    int m;
    m=x*y;
    return m;
}

int factorialA (float x)
{
    int fact;
    if (x<1){
        fact=-1;
    }else {
     for (int i=1;i<=x;i++){
        fact=fact*i;
    }
    }
    }
/*float factorialA (float x)
{
    if (x<1)
    {
        return 1;
    }
    else
    {
        return x*(factorialA(x-1));
    }
}
*/

/*float factorialB(float y)
{
    if (y<1)
    {
        return 1;
    }
    else
    {
        return y*(factorialB(y-1));
    }
}

}*/
