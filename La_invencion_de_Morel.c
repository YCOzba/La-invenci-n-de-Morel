#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h> // toupper fonksiyonu için eklendi

int main(){
    srand(time(NULL));

    int saglik=100;
    int enerji=100;
    int yemek_sayisi=0;
    int siginak=0;
    char komut;


    printf("---Morelin Buluşu---");
    do{
        printf("\nYapacağınız hamleyi seçin((A)vlan,(S)ığınak,(E)nvanter,(R)dinlen,(F)Tehlike,(P)Gizem,(X)Çıkış: ");
        scanf(" %c",&komut);
        komut = toupper(komut); // Küçük harf girilse bile büyütür (Örn: 'a' -> 'A')
        
        switch(komut){
            case 'A':
            if(enerji>=16){
                enerji-=15;
                printf("Avlanmaya daldın...\n\n");
                int sans =rand()%100;
                if(sans>50){
                    yemek_sayisi++;
                    printf("Bir yemek buldun. (Yeme:%d)\n",yemek_sayisi);
                }else{
                    saglik -=10;
                    printf("Av tarafından avlandın. (-10 sağlık:%d)\n",saglik);
                }
            }else{
                printf("Avlanamayacak kadar yorgunsun. (Gereken 15+)\n");
            }
            break;

            case'S':
            if(enerji>=10){
                enerji-=10;
                printf("Keşfe çıktın.\n");

                if(rand()%100<30){
                    if(siginak==0){
                        printf("Güvenli ve gözlerden ırak bir mağra buldun.\n");
                    }else{
                        printf("Mevcut bölgenden farklı bir alana yerleştin.");
                    }
                    siginak=1;
                }else{
                    printf("Bir sığınak bulamadın.\n");
                }
            }else{
                printf("keşif için halin yok. (Gereken enerji: 10+)\n");
            }
            break;

            case'R':
            if(yemek_sayisi>0){
                yemek_sayisi--;
                saglik +=20;
                enerji+=10;
                printf("Yemeğini yedin ve dinlendin. (+20 sağlık,+10 enerji)\n");
            }else{
                enerji+=10;
                printf("Yemeğin yok.Karnın aç uyudun (+10 Enerji)\n");
            }

            if(saglik>100) saglik=100;
            if(enerji>100) enerji=100;
            break;

            case 'F':
            printf("Gece çöküyor vahşi hayvanlar ortaya çıkmaya başladı.\n");

            for(int i=1;i<=3;i++){
                int hasar=rand()%15+5;

                if(siginak==1){
                    hasar=rand()%5+5;
                    printf("%d.Dalga:Sığınağında güvendesin. (Hasar:%d)\n",i,hasar);
                }else{
                    printf("%d.Dalga:Açıktasın. Saldırıya uğradın (Hasar:%d)\n",i,hasar);
                }
                saglik-=hasar;

                if(saglik<=0){
                    printf("Öldün.");
                    break;
                }
            }
            printf("Tehlike bitti. Sağlığın:%d\n",saglik);
            break;

            case 'P':
            {
                int sifre;
                printf("Üstünde rakam takımı olan kitlitli bir kutu karşına çıktı.\n");
                printf("Şifreyi çözene kadar bunla uğraşıcaksın!(ipucu:Havaya bak!Kaç tane güneş görüyorsun?\n)");
            
                do{
                    printf("Şifreyi Giriniz:");
                    scanf("%d",&sifre);

                    if(sifre!=2){
                        printf("Yanlış cevap! Gerçekliğe odaklanmıyorsun.Tekrar dene!\n");
                        enerji -=5;
                        printf("Çok kafa yordun(-5 Enerji)\n");
                    }
                }while(sifre !=2);
                printf("\nDoğru! İKİ güneş... Biri gerçek,biri Morelin gerçeği.\n");
                printf("Kapağı açıldı içinden sığır eti konservesi çıktı (+2 Yemek)\n");
                yemek_sayisi+=2;
                break;
            }

            case 'X':
            printf("Oyundan çıkılıyor.\n");
            break;

            default:
            printf("geçersiz simge girişi.Tekrar deneyebilirsin.\n");

        }
        if(saglik<=0){
            printf("Öldün.");
            break;
        }
    }while (komut!='X');
    
}