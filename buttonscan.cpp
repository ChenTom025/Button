#include <time.h>
#include <iostream>

#define KEY_RELEASED       0
#define SHORT_KEY_PRESSED  1
#define LONG_KEY_PRESSED   2

clock_t t1, t2;

void key_scan(int *KeyState, int *KeyValue, int *ClickCount, int *last_KeyValue);

int main() {

    int KeyState = KEY_RELEASED; // 按鍵狀態
    int KeyValue = 1;            // 獲取鍵值 (假設為1)，按下為0，釋放為1
    int last_KeyValue = 1;       // 鍵值暫存
    int ClickCount = 0;          // 計數器

    while (true) {
        printf("請輸入鍵值 = ");
        scanf_s("%d", &KeyValue);
        key_scan(&KeyState, &KeyValue, &ClickCount, &last_KeyValue);
    }
}

void key_scan(int *KeyState, int *KeyValue, int *ClickCount,int *last_KeyValue) {
   
    

    switch (*KeyState)
    {
    case KEY_RELEASED: 

        printf("釋放按鍵\n");
        if (*KeyValue == 0)
        {
            *KeyState = SHORT_KEY_PRESSED;
            *last_KeyValue = *KeyValue;
        }
        
        break;

    case SHORT_KEY_PRESSED:
        
        if (*KeyValue == *last_KeyValue){
            *KeyState = LONG_KEY_PRESSED;
            t1 = clock();
        }
        else{
            *KeyState = KEY_RELEASED;
        }

        break;

    case LONG_KEY_PRESSED:
        
        if (*KeyValue == *last_KeyValue){
            printf("按下按鍵\n");
        }
        else{
            *KeyState = KEY_RELEASED;
            t2 = clock();
            printf("%lf\n", (t2 - t1) / (double)(CLOCKS_PER_SEC));
            *ClickCount +=1;
            printf("共按了%d次", *ClickCount);
        }

        break;
    }

}