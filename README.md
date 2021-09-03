# Introduction

Sample source code for confirming the usage of `rr` command with vscode?

# Usage with Command line

```Shell
$ cd <work directory>
```

```ShellSession
$ git clone https://github.com/aRaikoFunakami/rr_test.git
$ cd rr_test/
$ gcc -g -O0 -pthread a.c
$ rr record ./a.out
$ rr replay
```

# Usage with vscode
