#include <stdio.h>
int main() {
int data[10];
int datatrec[10];
int c,c1,c2,c3,i;
printf("Enter 4 bits of data: ");
scanf("%d",&data[0]);
scanf("%d",&data[1]);
scanf("%d",&data[2]);
scanf("%d",&data[4]);
data[6]= data[0] ^ data[2] ^ data[4];
data[5]= data[0] ^ data[1] ^ data[4];
data[3]= data[0] ^ data[1] ^ data[2];
printf("\nencoded data is :");
for(i=0;i<7;i++){
printf("%d", data[i]);
}
printf("\nEnter recived 7 bits: ");
for(i=0;i<7;i++){
scanf("%d",&datatrec[i]);
}
c1 = datatrec[6] ^ datatrec[4] ^ datatrec[2] ^ datatrec[0];
c2 = datatrec[5] ^ datatrec[4] ^ datatrec[1] ^ datatrec[0];
c3 = datatrec[3] ^ datatrec[2] ^ datatrec[1] ^ datatrec[0];
c = c3 * 4 + c2 * 2 + c1;
if(c==0){
printf("\nNo error recived in data");
} else{
printf("\nerror recived at bit position: %d ", c);
printf("\nData sent :");
for(i=0;i<7;i++) printf("%d", data[i]);
printf("\nData recived :");
for(i=0;i<7;i++) printf("%d", datatrec[i]);
printf("\nData Corrected :");
int idx = 7 - c;
datatrec[idx] = datatrec[idx] ^ 1;
for(i=0;i<7;i++) printf("%d", datatrec[i]);
printf("\n");
}
return 0;
}