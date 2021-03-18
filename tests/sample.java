class Factorial {
  public static void main () {
    System.out.println (42);
    int y;
    y = 7;
    System.out.println(y);
    int x = 67;
    x = y + 3;
    System.out.println(x);
    if (x > 3) {
        x = 2;
        System.out.println(x);
        }
    else
        System.out.println(x);

    x = 0;
    while (x < 10) {
      System.out.println(x);
      x = x + 1;
    }
  }
}

class Fac {
  public int ComputeFac (int num) {
    assert (num > -1);
    int num_aux;
    if (num == 0)
      num_aux = 1;
    else
      num_aux = num * this.ComputeFac(num - 1);
    return num_aux;
  }
}