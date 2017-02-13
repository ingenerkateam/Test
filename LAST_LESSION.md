### Используте структуры
До:  
```cpp
void drawVopros(  
                int xOtveta1, int yOtveta1, const char* textOtveta1, 
                int xOtveta2, int yOtveta2, const char* textOtveta2);
```
После:
```cpp
void drawOtvet(Otvet* otvet)
```
