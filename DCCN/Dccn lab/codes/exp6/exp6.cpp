#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int n, r;
struct frame {
 char ack;
 int data;
} frm[10];
int sender(void);
void recvack(void);
void resend_sr(void);
void resend_gb(void);
void selective(void);
void goback(void);
/* Data Comm. & Computer Network Lab [DCCN ] CSE Department ASET, AUM. */
void goback() {
 sender();
 recvack();
 resend_gb();
 printf("\n all frames sent succesfully \n");
}
void selective() {
 sender();
 recvack();
 resend_sr();
 printf("\n all frames sent succesfully \n");
}
int sender() {
 int i, data;
 printf("\nEnter the no.of frames to be sent:");
 scanf("%d", &n);
 for (i = 1; i <= n; i++) {
 printf("\nEnter the data for frames [%d]: ", i);
 scanf("%d", &data);
 frm[i].data = data;
 frm[i].ack = 'y';
 }
 return 0;
}
void recvack() {
 int i;
 rand();
 r = rand() % n;
 frm[r].ack = 'n';
 for (i = 1; i <= n; i++) {
 if (frm[i].ack == 'n')
 printf("\nThe frame number %d is not recieved\n", r);
 }
}
void resend_sr() {
 printf("\nresending frame %d", r);
 sleep(2);
 frm[r].ack = 'y';
 printf("\nThe received frame is %d", frm[r].data);
}
void resend_gb() { // Fixed: Changed from int to void
 int i;
 printf("\nGo-Back-N: Resending from frame %d onwards.\n", r);
 for (i = r; i <= n; i++) {
 printf("Resending frame %d with data %d\n", i, frm[i].data);
 frm[i].ack = 'y';
 }
}
int main() {
 int ch;
 printf("1. Go Back N\n2. Selective Repeat\nEnter choice: ");
 scanf("%d", &ch);
 switch (ch) {
 case 1:
 goback();
 break;
 case 2:
 selective();
 break;
 default:
 printf("Invalid choice\n");
 }
 return 0;
}
