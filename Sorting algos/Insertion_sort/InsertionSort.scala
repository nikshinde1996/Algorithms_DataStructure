object InsertionSort {
  def main(args: Array[String]): Unit = {
    val elements = List(9, 8, 7, 6, 5, 4, 3, 2, 1)
    println(isort(elements).toString)
  }

  def isort(xs: List[Int]): List[Int] = {
    if(xs.isEmpty) Nil
    else insert(xs.head, isort(xs.tail))
  }

  def insert(x: Int, xs: List[Int]): List[Int] = {
    if(xs.isEmpty || x <= xs.head) x :: xs
    else xs.head :: insert(x, xs.tail)
  }
}
