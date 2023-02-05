
#include <stdio.h>

enum enum1 {
  V1,
  V2,
};

enum enumWithSaveValue {
  Value1=1,
  Value2=1,
};

// enumWithSaveValue 中已存在Value1，在其他枚举中就不能再有同名的Value1
// enum enumWithSaveName {
//   Value1=1,
//   Value3=1,
// };

int main() {
  printf("V1 = %i\n", V1);
  printf("Value1 = %i, Value2 = %i\n", Value1, Value2);
  return 0;
}
