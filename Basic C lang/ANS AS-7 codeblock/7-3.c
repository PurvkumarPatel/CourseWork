/* 3. Write a C program to swap first and last digits of a number. */
int main()
{
    int num,x=0,d1,df,y,s1,s2,p;
   printf("enter the number:\n");
   scanf("%d",&num);
   y=num;
  do
    {
    y/=10;
    x++;
    }
  while(y>0);

   df=num%10;
   x=x-1;
   p=pow(10,x);
  if(p%2!=0)
    {
    p++;
    }
   d1=num/p;
   d1=d1*p;
   s1=d1+df;
   num= num-s1;
   df=s1/p;
   d1=s1%10;
   d1=d1*p;
   s2=df+d1;
   num=num+s2;

   printf("%d ",num);
}
