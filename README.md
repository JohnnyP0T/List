# List
Doubly linked list.

## Списки

*Связный список* – динамическая структура данных,
состоящая из узлов, каждый из которых содержит как
собственно данные, так и одну или две ссылки на
следующий и/или предыдущий узел списка.
Порядок элементов списка может не совпадать с порядком
расположения элементов данных в памяти, а порядок
обхода списка всегда задается его внутренними связями.

*Двусвязный список*
Ссылки в каждом узле указывает на предыдущий и
последующий узел в списке.

![DoublyLinkedList](https://i.imgur.com/QCPNEZ3.png)

### Операции
* Поиск элемента
* Вставка элемента
* Удаление элемента
* Объединение списков

### Преимущества и недостатки
Недостатки

* Нет быстрого доступа по индексу (индексированные
списки).
* Расходуется дополнительная память.
* Узлы могут располагаться в памяти разреженно, что не
позволяет использовать кэширование процессора.

Преимущества

* Быстрая вставка узла.
* Быстрое удаление узла.

### Итоги

![complexity](https://i.imgur.com/5bAED8m.png)