#define BUCKET_SIZE 50

typedef struct cell {
  int key;
  int data;
  struct cell *next;
} CELL;

CELL *table[BUCKET_SIZE];

int keyequal(int a, int b) {
  return a == b;
}

int keylt(int a, int b) {
  return a > b;
}

void init() {
  int i;
  for (i = 0; i < BUCKET_SIZE; i++) {
    table[i] = NULL;
  }
}

int *find(int key) {
  CELL *p;

  for (p = table[hash(key)]; p != NULL; p = p->next) {
    if (keyequal()) {
    }
  }
}
