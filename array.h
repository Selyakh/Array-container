// Copyright (c) 2024 Irina Selyakh
//
// Данное программное обеспечение распространяется на условиях лицензии MIT.
// Подробности смотрите в файле LICENSE

#ifndef ARRAY_H
#define ARRAY_H
#include <cstddef>
#include <utility>

template <class T, size_t N>
struct Array {
  T data[N];

  [[nodiscard]] size_t Size() const {
    return N;
  }

  [[nodiscard]] const T& operator[](
      size_t index) const {  // Метод не изменяет состояние объекта Array.
                             // Это позволяет вызывать метод для константных объектов Array.
    return data[index];
  }
  [[nodiscard]] T& operator[](size_t index) {
    return data[index];
  }

  [[nodiscard]] const T& Front() const {
    return data[0];
  }

  [[nodiscard]] T& Front() {
    return data[0];
  }

  [[nodiscard]] const T& Back() const {
    return data[N - 1];
  }

  [[nodiscard]] T& Back() {
    return data[N - 1];
  }

  [[nodiscard]] const T* Data() const {  // возвращает указатель на начало массива;
    return &data[0];
  }

  [[nodiscard]] T* Data() {
    return &data[0];
  }

  [[nodiscard]] bool Empty() const {
    return Size() == 0;
  }

  void Fill(const T& value) {
    for (size_t i = 0; i < N; ++i) {
      data[i] = value;
    }
  }

  void Swap(Array<T, N>& other) {
    std::swap(data, other.data);
  }
};
#endif