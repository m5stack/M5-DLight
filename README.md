# M5-DLight

## Overview

### SKU:U136/U134

M5Stack-**Unit & Hat DLight** driver library, based on BH1750FVI sensor to achieve ambient light detection.

## Initialization

`begin()` now returns a `bool` that indicates whether the device acknowledged the `POWER_ON` command on the configured I2C address.

- `true`: a device acknowledged at the configured address, which is treated as sensor present
- `false`: no device acknowledged at the configured address

Existing code that ignores the return value will continue to work.

```cpp
M5_DLight sensor;

if (sensor.begin()) {
	uint16_t lux = sensor.getLUX();
}
```

## Related Link

[Document & Datasheet - M5Unit-DLight](https://docs.m5stack.com/en/unit/dlight)

[Document & Datasheet - M5Hat-DLight](https://docs.m5stack.com/en/hat/hat_dlight)


## License

[M5-DLight - MIT](LICENSE)
