matrix_multiply <- function(mat1, mat2) {
  n_elems <- ncol(mat1)
  result <- matrix(0, nrow(mat1), ncol(mat2))

  for (i in seq(nrow(mat1))) {
    for (j in seq(ncol(mat2))) {
      for (k in seq(n_elems)) {
        # print(mat1[i,k])
        # print(mat2[k,j])
        result[i,j] = result[i,j] + mat1[i,k] * mat2[k,j]
      }
    }
  }
  
  return (result)
}

mat1 <- matrix(c(1,0,2,2,1,3,1,0,4), nrow=3, ncol=3)
mat2 <- matrix(c(2,6,1,5,7,8), nrow=3, ncol=2)

mat1
mat2

matrix_multiply(mat1, mat2)
