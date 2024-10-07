#include "../include/mySimpleComputer.h"
#include "console.h"
#include <stdio.h>

int
main ()
{
  // Инициализация оперативной памяти, аккумулятора, счетчика команд и
  // регистра флагов
  sc_memoryInit ();
  sc_accumulatorInit ();
  sc_icounterInit ();
  sc_regInit ();

  // Установка произвольных значений в оперативную память и вывод ее
  // содержимого (в данном примере установим все ячейки памяти в значение 5)
  for (int i = 7; i < 26; i++)
    {
      sc_memorySet (i, 5);
    }

  // Вывод содержимого оперативной памяти
  for (int i = 0; i < MEMORY_SIZE; i++)
    {
      if ((i) % 10 == 0)
        {
          printf ("\n");
        }
      printCell (i);
    }
  printf ("\n");

  // Попытка задать недопустимое значение ячейке памяти
  int invalidMemoryValue = 40000;
  int result = sc_memorySet (10, invalidMemoryValue);
  printf ("Status of setting invalid memory value: %d\n", result);

  // Установка произвольных значений флагов и вывод их содержимого
  sc_regSet (FLAG_OVERFLOW_MASK, 1);
  sc_regSet (FLAG_DIVISION_BY_ZERO_MASK, 0);
  sc_regSet (FLAG_OUT_OF_MEMORY_MASK, 1);
  sc_regSet (FLAG_INVALID_COMMAND_MASK, 0);
  sc_regSet (FLAG_IGNORE_CLOCK_MASK, 1);
  printFlags ();

  // Попытка установить некорректное значение флага
  result = sc_regSet (FLAG_OVERFLOW_MASK, 2);
  printf ("Status of setting invalid flag value: %d\n", result);

  // Установка значения аккумулятора и вывод его на экран
  sc_accumulatorSet (100);
  printAccumulator ();

  // Попытка задать недопустимое значение аккумулятору
  int invalidAccValue = 40000;
  result = sc_accumulatorSet (invalidAccValue);
  printf ("Status of setting invalid accumulator value: %d\n", result);

  // Установка значения счетчика команд и вывод его на экран
  sc_icounterSet (50);
  printCounters ();

  // Попытка задать недопустимое значение счетчику команд
  int invalidCounterValue = -10;
  result = sc_icounterSet (invalidCounterValue);
  printf ("Status of setting invalid counter value: %d\n", result);

  // Декодирование произвольной ячейки памяти и значения
  // аккумулятора
  printCell (8);
  printf ("\n");
  printAccumulator ();

  // Кодирование команды и вывод полученного значения в разных системах
  // счисления
  int command = 0x33;
  int encodedValue;
  sc_commandEncode (0, command, 0x59, &encodedValue);
  printDecodedCommand (encodedValue);
  printf ("\n");

  return 0;
}
