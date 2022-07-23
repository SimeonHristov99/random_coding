object Multiplication {

  def persistence(n: Int, result: Int = 0): Int = {
    if(n < 10) {
        return result
    }

    return persistence(
        n.toString.map(_.asDigit).toList.product,
        result + 1
    )
  }

}