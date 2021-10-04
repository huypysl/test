#include<iostream>
using namespace std;
//Khai bao cau truc sinh vien
struct SinhVien{
	char HoTen[30];
	int NamSinh;
	int GioiTinh;
};
typedef struct SinhVien SV;
//Ham nhap thong tin sinh vien
void NhapThongTinSinhVien(SV &sv)
{
	cout<<"\nNhap ho va ten sinh vien: ";
	fflush(stdin);
    cin.getline(sv.HoTen,30);
	cout<<"\nNhap nam sinh cua sinh vien: ";
	cin>> sv.NamSinh;
	do{
	cout<<"\nNhap gioi tinh cua sinh vien(nam=0, nu=1):";
	fflush(stdin);
	cin >> sv.GioiTinh;
	}while(sv.GioiTinh<=0 && sv.GioiTinh>=1);
	
}
	//Xuat ra thong tin sinh vien
void xuatthongtinsv(SV sv)
        {
		cout<<"Ho ten sinh vien la: "<< sv.HoTen << endl;
		cout<< "Nam sinh cua sinh vien la: "<< sv.NamSinh << endl;
		cout<< "tuoi:"<< 2021- sv.NamSinh<< endl;
		cout <<"Gioi tinh : ";
		if (sv.GioiTinh==0)
			cout<<"nam\n";
	       else
	          cout<<"nu\n";
	      }
	    
	
int main(){
	int n;
	do{
		cout<<"Nhap so luong sinh vien: ";
		cin >> n;
		if(n<= 0)
		cout<<"Nhap so luong sinh vien khong hop le. Xin nhap lai!!";
	}while(n<= 0);
	SV a[n];
	int i;
	//Nhap n sinh vien
	for(i=0; i<n; i++)
	{
		cout<<"\nNhap thong tin cua sinh vien thu "<<(i+1) << ": ";
		NhapThongTinSinhVien(a[i]);
	} 
	//in thong tin sv
		for(i=0; i< n; i++)
	{
        xuatthongtinsv(a[i]);
    }
	//Tim sinh vien co tuoi nho nhat

	int min = a[0].NamSinh;
	for(i=0; i< n; i++)
	{
		if(min < a[i].NamSinh)
		min = a[i].NamSinh;
	}
	for(i =0; i< n; i++)
	{
		if(min == a[i].NamSinh)
		{
			cout<<"\nSinh vien co tuoi be nhat : ";
			cout<<"\nHo va ten : "<< a[i].HoTen <<endl;
			cout<<"Gioi tinh : ";
		if (a[i].GioiTinh==0)
		
			cout<<"nam\n";
	    
	   else
	    
	      cout<< "nu\n";
	    
	
		}
	}
	//tim sinh vien nu lon tuoi nhat


	int maxn=a[0].NamSinh,kt=0;
    for(int i= 0; i< n; i++)
    {
	if(a[i].GioiTinh==1)
	{
		maxn = a[i].NamSinh;
		kt=1;
		break;
	}
    }
    if(kt==0)
    cout<<"\nTrong danh sach khong co sinh vien nu!"<<endl;
    else{
    for(int i = 0; i< n; i++)
    {
	if(a[i].NamSinh < maxn)
	{
		maxn = a[i].NamSinh;
	}
    }
    cout<<"\nSinh vien nu co tuoi lon nhat: ";
    for(int i= 0; i< n; i++)      
    {
	if(maxn == a[i].NamSinh && a[i].GioiTinh==1)
	xuatthongtinsv(a[i]);
   }
   }
        //tinh do tuoi trung binh sinh vien nu
        
        int tong=0,nu;
        float tuoi_tb_nu;
        for(i=0;i<n;i++){
          if(a[i].GioiTinh==1)
          {
          	nu++;
          	tong+=2021-(a[i].NamSinh);
          	tuoi_tb_nu=(float)tong/nu;
          }
          }
          cout<<"\ndo tuoi trung binh cua sv nu la:"<< tuoi_tb_nu<< endl;
          
		  //Tinh do tuoi trung binh cua sinh vien nam
	    float tuoi_tb_nam;
	     int nam= 0,tong1=0;

	    for(i=0;i<n;i++)
          if(a[i].GioiTinh==0)
          {
          	nam++;
          	tong1+=2021-(a[i].NamSinh);
          	tuoi_tb_nam=(float)tong1/nam;
          }
          cout<<"\ndo tuoi trung binh cua sv nam la:"<< tuoi_tb_nam<< endl;
          //tuoi trung binh cua toan bo sinh vien
        float tuoi_tb;
	     int tongtb=0;
	    for(i=0;i<n;i++)
          	
          	tongtb+=2021-(a[i].NamSinh);
          	tuoi_tb=(float)tongtb/n;
          
          cout<<"\ndo tuoi trung binh cua sv la:"<< tuoi_tb<< endl;
          
	system("pause");
	return 0;
}
