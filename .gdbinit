break driver_init
  condition $bpnum a == 0
  commands
    silent
    p a
    p b
    continue
  end
