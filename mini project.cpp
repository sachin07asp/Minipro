#include <stdio.h>
#include <string.h>
 
      
struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};	 
             
struct Bill {
    int billNumber;
    struct Product products[100];
    int productCount;
    float totalAmount;
    
};
void addProduct(struct Bill *bill, int id, const char *name, float price, int quantity) {
    struct Product p;
    p.id = id;
    strcpy(p.name, name);
    p.price = price;
    p.quantity = quantity;

    bill->products[bill->productCount++] = p;
}

void calculateTotal(struct Bill *bill) {
    bill->totalAmount = 0;
    for (int i = 0; i < bill->productCount; i++) {
        bill->totalAmount += bill->products[i].price * bill->products[i].quantity;
    }
}

void printReceipt(struct Bill *bill) {
    printf("Receipt – Bill No: %d\n", bill->billNumber);
    printf("%-10s %-20s %-10s %-10s %-10s\n", "ID", "Product", "Price", "Qty", "Amount");

    for (int i = 0; i < bill->productCount; i++) {
        struct Product p = bill->products[i];
        printf("%-10d %-20s %-10.2f %-10d %-10.2f\n",
               p.id, p.name, p.price, p.quantity, p.price * p.quantity);
    }

    printf("\nTotal Amount: %.2f\n", bill->totalAmount);
}

int main() {
    struct Bill bill;
    bill.billNumber = 1;
    bill.productCount = 0;

     addProduct(&bill, 101, "Milk", 30.5, 2);
    addProduct(&bill, 102, "Bread", 20.0, 1);
    addProduct(&bill, 103, "Eggs", 5.0, 12);

    // Calculate total and print receipt
    calculateTotal(&bill);
    printReceipt(&bill);

    return 0;
}
 