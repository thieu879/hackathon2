#include<stdio.h>
#include<string.h>
struct contactList{
	int id;
	char name[50];
	char phone[12];
	char address[50];
	int status;
	
};
typedef struct contactList cl;
void input (cl*temp){
	printf("nhap id\n");
	getchar();
	scanf("%d",&temp->id);
	printf("nhap ten\n");
	getchar();
	gets(temp->name);
	printf("nhap so dien thoai\n");
	getchar();
	gets(temp->phone);
	printf("nhap dia chi\n/");
	gets(temp->address);
	printf("nhap trang thai\n");
	getchar();
	scanf("%d",&temp->status);
}
void output (cl*temp){
	printf("id: %d,ten: %s,so dien thoai: %s,dia chi: %s,trang thai: %d",temp->id,temp->name,temp->phone,temp->address,temp->status);
}
int main(){
	int n,i;
	int choice;
	int index =2;
	int count;
	cl contactList[2]=
	{
		{1,"Nguyen Gia Thieu","0355483082","Viet Nam",1},
		{2,"Nguyen Duc Tho","0987654321","Dong Lao",1}		
	};
	do{
		printf("************************MENU**************************\n");
		printf("1. In toan bo danh sach contact co o trong mang contactList tren cung mot hang\n");
		printf("2. Thuc hien chuc nang them moi contact vao vi tri cuoi cung cua contactList, Thong tin contact do nguoi dung nhap vao\n");
		printf("3.Thuc hien chuc nang cap nhat thông tin cua mot contact. Cho nguoi dung nhap vao ten contact muon chinh sua, neu tim thay thi cho nguoi dung tien hanh nhap vao thong tin moi cho contact do. Neu khong tim thay thi in ra man hinh (Khong tim thay)\n");
		printf("4. Thuc hien chuc nang xoa mot contact. Cho nguoi dung nhap vao ten contact muon xoa, neu tim thay thi cho nguoi dung tien hanh xoa contact do di. Neu khong tim thay thi in ra man hinh (Khong tim thay)\n");
		printf("5. Thuc hien chuc nang sap xep (Su dung thuat toan sap xep noi bot) va in ra danh sach contact da duoc sap xep\n");
		printf("6. Thuc hien chuc nang tim kiem (Su dung thuat toan tim kiem nhi phan) và in ra thong tin cua contact tren cung mot hang (Tim kiem theo ten contact)\n");
		printf("7. Thuc hien chuc nang tim kiem (Su dung thuat toan tim kiem tuyen tinh) va in ra toan bo thong tin contact (Tim kiem theo status)\n");
		printf("Vui long nhap lua chon:\n");
		scanf("%d",&choice);
		getchar();
		switch(choice){
			case 1:
				 for (i=0;i<index;i++) {
                    printf("%d:",i+1);
                    output(&contactList[i]);
                    printf("\n");
                }
                break;
            case 2:
            	break;
            case 3:
            	 count=0;
            	int find_id;
                printf("nhap vao contact_id can cap nhat:");
                scanf("%d",&find_id);
                for (i=0;i<index;i++) {
                    if (contactList[i].id == find_id)
                        {input(&contactList[i]);
						count =1;
						}
    			}
    			if(count==0){
    				printf("khong tim thay\n");
				}
                break;
            case 4 :
            	 count=0;
        	int delete_id;
                printf("nhap vao id can xoa:");
                scanf("%d",&delete_id);
                for (i=0;i<index;i++) {
                    if (contactList[i].id == delete_id)
                    for (int j=i;j<index-1;j++){
                      contactList[i] = contactList [i+1];	
                    	count=1;
					}
                }
                if(count==0){
    				printf("khong tim thay\n");
				}
                index--;
                break;
            case 5:
            	break;
            case 6 :
            	count=0;
        	int find_contactId ;
        	printf("nhap contact_Id can tim :");
        	scanf("%d",&find_contactId);
			for (i=0;i<index;i++){
				if(contactList[i].id == find_contactId){
				output(&contactList[i]);
				count=1;		
				}
			}
			if(count==0){
    				printf("khong tim thay\n");
				}
		}
	}while(choice!=8);
}
