Very simple library for the MCP3008 10 bit 8 channels DAC.

Using hardware SPI transactions.

Inspired by a very good tutorial found here:
https://rheingoldheavy.com/mcp3008-tutorial-02-sampling-dc-voltage/

The other library I found by nodesign (https://github.com/nodesign/MCP3008) was using bit banging for the SPI communications with the chip and was causing troubles with the other devices on the SPI bus. So I decided to write my own using my findings on Internet.
