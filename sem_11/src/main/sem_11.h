#ifndef SRC_MAIN_SEM_11_H_
#define SRC_MAIN_SEM_11_H_

class Base {
 private:
  int b_;

 public:
  Base() = default;
  explicit Base(int b) : b_(b){};
  void print();
  ~Base() = default;
  ;
};

#endif  // SRC_MAIN_SEM_11_H_
