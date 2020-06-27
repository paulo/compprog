import scala.collection.mutable.ArrayBuffer
//The Mr. Bond problem.
//DONE
object Problem007 {

  //I don't add the prime 1 as it would conflict with the isPrime logic
  var primeList = ArrayBuffer[Int](2,3,5)
  var primeCount = 4

  def main(args: Array[String]): Unit = {
    var currentNumber = 7

    while (primeCount < 10002) {
      if(isPrime(currentNumber)) {
        primeList += currentNumber
        primeCount += 1
      }
      currentNumber += 1
    }
    println(primeList.last)
  }

  def isPrime(number: Int): Boolean = {
    primeList.filter(_ <= math.floor(math.sqrt(number))).filter(number%_ == 0).size == 0
  }
}