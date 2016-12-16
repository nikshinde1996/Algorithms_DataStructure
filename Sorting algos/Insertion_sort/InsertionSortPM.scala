object InsertionSortPM {
  def main(args: Array[String]): Unit = {
    val elements = List(5, 4, 3, 2, 1)
    println(isort(elements).toString)
  }

  def isort(xs: List[Int]): List[Int] = xs match {
    case List() => List()
    case x :: xs => insert(x, isort(xs))
  }

  def insert(x: Int, xs: List[Int]): List[Int] = xs match {
    case List() => List(x)
    case y :: ys => if(x <= y) x :: xs else y :: insert(x, ys)
  }
}
