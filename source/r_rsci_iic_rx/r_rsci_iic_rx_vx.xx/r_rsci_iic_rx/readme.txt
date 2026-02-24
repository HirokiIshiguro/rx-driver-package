PLEASE REFER TO THE APPLICATION NOTE FOR THIS DRIVER FOR MORE INFORMATION

r_rsci_iic_rx
=========

Overview
--------
The RSCI simple I2C mode fit module provides a method to transmit and receive data between the master and slave devices using the serial communications interface (RSCI). The RSCI simple I2C mode is in compliance with single master mode of the XP I2C-bus (Inter-IC-Bus) interface.

The driver supports the channels available on the mcu. (Maximum 5 channels)
The driver can be reduced in size by removing code used for parameter checking or for unused channels.
These configuration options can be found in "r_config\r_rsci_iic_rx_config.h".

Features
--------
* Single master mode (slave transmission or slave reception is not supported).
* Circuit to generate waveforms for conditions.
* Communication mode can be normal or fast mode and the maximum communication rate is 384 kbps.

File Structure
--------------
r_rsci_iic_rx
|   readme.txt
|   r_rsci_iic_rx_if.h
|
+---doc
|   |
|   +---en
|   |   r01an8028ej{VERSION_NUMBER}-rx-rsci-iic.pdf
|   |
|   +---ja
|       r01an8028jj{VERSION_NUMBER}-rx-rsci-iic.pdf
|
+---src
    |   r_rsci_iic_rx.c
    |   r_rsci_iic_rx_platform.h
    |   r_rsci_iic_rx_private.h
    |
    +---targets
        |
        +---rx26t
        |        r_rsci_iic_rx26t.c
        |        r_rsci_iic_rx26t_private.h
        |
        +---rx260
        |        r_rsci_iic_rx260.c
        |        r_rsci_iic_rx260_private.h
        |
        +---rx261
        |        r_rsci_iic_rx261.c
        |        r_rsci_iic_rx261_private.h
        |
        +---rx660
        |       r_rsci_iic_rx660.c
        |       r_rsci_iic_rx660_private.h
        |
        +---rx671
        |       r_rsci_iic_rx671.c
        |       r_rsci_iic_rx671_private.h
        :

r_config
    r_rsci_iic_rx_config.h
    r_rsci_iic_rx_pin_config.h

