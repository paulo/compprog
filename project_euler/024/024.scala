import scala.collection.mutable.ArrayBuffer

object Problem024 {

  var list = ArrayBuffer[Double]()

  def main(args: Array[String]): Unit = {
    permutation("", "0123456789")
    println(list.sortWith(_ < _)(999999))
  }

  def permutation(prefix: String, str: String): Unit = {
    if (str.length == 0) {
     list += prefix.toDouble
    } else {
      for(i <- 0 until str.length){
        permutation(prefix + str.charAt(i), str.substring(0, i) + str.substring(i+1, str.length))
      }
    }
  }
}