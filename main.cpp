#include <iostream>
using namespace std;
#include "queue.h"

int main(int argc, char *argv[]) {
  Queue q;
  int price, cash, change;

  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == 'x') {
      price = q.dequeue();

      do {
        cout << "Cash: ";
        cin >> cash;

        if (cash < price)
          continue;
        if (cash > price) {
          change = cash - price;
          cout << "Change: " << change << endl;
          cout << "Thank you" << endl;
          break;
        }

        if (cash == price)
          cout << "Thank you!" << endl;
        break;
      } while (1);
      i--;
    } else {
      q.enqueue(atoi(argv[i]), atoi(argv[i + 1])); // q.enqueue(ord,qty)
      cout << "Order received" << endl;
      i++;
    }
  }
}
