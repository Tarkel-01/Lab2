# Lab_2 by Alexander Romanenko

1) Написать классы Vector и Matrix для хранения и обработки одномерных и
двумерных массивов, соответственно. Реализовать задание 2 лабораторной работы №1
с помощью созданных классов. Все функции оформить в виде методов классов.
В коде отразить следующее:
  * Выделение и освобождение динамической памяти производить в конструкторах и
  деструкторах классов, соответственно.
  
  * В классе Vector перегрузить оператор индексации []. В классе Matrix добавить
  методы, которые позволяют получить и установить значение элемента массива с индексом [i][j], T –
  это тип элементов массива по варианту (int или double):
  
  
2) Написать класс Fraction для представления обыкновенных дробей (как отношения
двух целых чисел x/y). Перегрузить операторы +, -, *, / для дробей. Реализовать метод
void reduce() для сокращения дроби, а также статические методы:

* Функция для нахождения наибольшего общего делителя чисел n и m:

```
    int gcd(int n, int m)
```

* Перегруженные методы вывода десятичной дроби в виде обыкновенной (например, при значении decimal_fraction = 0.43 на экране должно
  вывестись 43/100, при 0.25 – 1/4 и т.д.):
  
  ```
    void printAsFraction(double decimal_fraction)
    void printAsFraction(char* decimal_fraction)
  ```
  
* Также реализовать в виде статического члена класса счетчик всех созданных на
данный момент в программе экземпляров дробей.
* Продемонстрировать работу созданного класса. Создать несколько объектов дробей.
Произвести операции сложения, вычитания, умножения и деления дробей. Вывести
на экран результаты. Показать также результаты работы статических методов класса.

3) Написать собственный класс, в соответствии с вариантом. Продемонстрировать в коде
инкапсуляцию данных, применение конструкторов без параметров и с параметрами
для инициализации данных. Класс должен содержать метод `serialize()` для
сохранения данных класса в файл и метод `deserialize()` для чтения данных класса
из файла по умолчанию в текущей директории, а также перегруженные методы
`serialize(const std::string& filename)` и `deserialize(const std::string&
filename)` для работы с файлом с указанным в параметре именем.

`Примечание: Вы можете вводить дополнительные закрытые свойства и метода класса,
не указанные явно в задании, но помогающие решить поставленные задачи.`

Вариант 9

_Класс_ **Самолеты**

 
`Данные: модель, авиалинии, год выпуска, вместимость, количество пассажиров.`

Создать массив из 3 самолетов и установить их данные с помощью сеттеров. Еще один
самолет создать отдельно в куче и установить его данные в конструкторе с
параметрами. В главной функции проимитировать три рейса – случайным образом
сформировать фактическое количество пассажиров и просчитать процент заполнения
каждого самолета. Вывести информацию о самолетах, отсортировав их в порядке
убывания среднего процента заполнения за три рейса
