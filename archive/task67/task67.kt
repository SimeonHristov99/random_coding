// https://www.mathsisfun.com/algebra/trig-cosine-law.html
// 9 + 4 - 2*3*2*cos(135)
// https://kotlinlang.org/docs/packages.html
// https://kotlinlang.org/api/latest/jvm/stdlib/kotlin.math/

import kotlin.math.*

fun spiderToFly(spider: String, fly: String): Double {
    // get the first letter from both coordinates
    // and calculate the angle based on the ASCII distiance between
    // the letters
    var angle = (abs(spider[0].code - fly[0].code) * 45).toDouble();
    angle = angle * PI / 180;

    // get a
    var a = spider[1].digitToInt().toDouble()
    
    // get b
    var b = fly[1].digitToInt().toDouble()
    
    // use formula
    return sqrt(a.pow(2) + b.pow(2) - 2*a*b*cos(angle))
}
