function mod256WithoutMod($number)
{
    if(256 > $number && $number > -256) {
        return $number;
    }

    return $number > 0 ? mod256WithoutMod($number - 256) :  mod256WithoutMod($number + 256);
}