setwd('~/Dev/random_coding/task61/')

df <- data.frame(name = c('n1', 'n2'),
                 age = c(5, 15))
head(df)
str(df)

df <- read.csv('train.csv')

names(df)
dim(df)

preprocess <- function(df) {
  df <- data.frame(df)
  
  # Removing missing values
  df <- na.omit(df)
  # Removing "PassengerId" column
  df <- subset(df, select = -c(PassengerId, Name, Ticket))
  
  return (df)
}

df <- preprocess(df)

y <- subset(df, select = Survived)
head(y)

X <- subset(df, select = -Survived)
head(X)

summary(X)
str(X)
X$Pclass <- as.factor(X$Pclass)
str(X)
table(X$Pclass)
plot(X$Pclass)
plot(X)
plot(X$Pclass, X$Age)