# BigNumber
Big integer and float number with 16 bytes memory (C++)

Use:

main.cpp
```
#include <iostream>
#include "Qint.h"
int main()
{
  Qint num("2353476535675435675435643263245");
  Qint num1("884736969377375657");
  
  std::cout << num << " + " << num1 << " = " << num + num1 << std::endl;
  
  return 0;
}
```
