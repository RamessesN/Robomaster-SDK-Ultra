from robomaster_ultra import led
from robomaster_ultra import robot

if __name__ == "__main__":
    ep_robot = robot.Robot()
    ep_robot.initialize(conn_type='ap')

    version = ep_robot.get_version()
    print("Robot Version: {0}".format(version))

    ep_led = ep_robot.led

    ep_led.set_led(
        comp=led.COMP_ALL,
        r=255,
        g=0,
        b=0,
        effect=led.EFFECT_ON
    )

    ep_robot.close()