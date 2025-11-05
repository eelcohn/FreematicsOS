#pragma once

/* Modes (service codes) */
#define SERVICE_LIVE_DATA								0x01	// Show live data
#define SERVICE_FREEZE_FRAME_DATA						0x02	// Show freeze frame data
#define SERVICE_SHOW_STORED_DTCS						0x03	// Show stored Diagnostic Trouble Codes (DTC's)
#define SERVICE_CLEAR_DTCS_AND_STORED_VALUES			0x04	// Clear Diagnostic Trouble Codes (DTC's) and stored values
#define SERVICE_OXYGEN_SENSOR_MONITORING				0x05	// Test results, oxygen sensor monitoring (non CAN only)
#define SERVICE_COMPONENT_MONITORING					0x06	// Test results, other component/system monitoring (Test results, oxygen sensor monitoring for CAN only)
#define SERVICE_SHOW_PENDING_DTCS						0x07	// Show pending Diagnostic Trouble Codes (detected during current or last driving cycle)
#define SERVICE_CONTROL_ONBOARD_COMPONENT				0x08	// Control operation of on-board component/system
#define SERVICE_REQUEST_VEHICLE_INFORMATION				0x09	// Request vehicle information



/* Mode 1 (Request Current Powertrain Diagnostic Data) PIDs */
#define PID_1_PIDS_SUPPORTED_01_20						0x00	// PID's supported 0x01 - 0x20
#define PID_1_MONITOR_STATUS_SINCE_DTC_CLEARED1			0x01	// Monitor Status Since DTC Cleared (bit encoded)
#define PID_1_MONITOR_STATUS_SINCE_DTC_CLEARED1			0x02	// Monitor Status Since DTC Cleared (bit encoded)
#define PID_1_FUEL_SYSTEM_STATUS						0x03	// Fuel System Status (bit encoded)
#define PID_1_ENGINE_LOAD								0x04	// Engine Load (%)
#define PID_1_COOLANT_TEMP								0x05	// Coolant Temperature (°C)
#define PID_1_SHORT_TERM_FUEL_TRIM_1					0x06	// Short Term Fuel Trim Bank 1 (%)
#define PID_1_LONG_TERM_FUEL_TRIM_1						0x07	// Long Term Fuel Trim Bank 1 (%)
#define PID_1_SHORT_TERM_FUEL_TRIM_2					0x08	// Short Term Fuel Trim Bank 2 (%)
#define PID_1_LONG_TERM_FUEL_TRIM_2						0x09	// Long Term Fuel Trim Bank 2 (%)
#define PID_1_FUEL_PRESSURE								0x0A	// Fuel Pressure (kPa)
#define PID_1_INTAKE_MAP								0x0B	// Intake Manifold Absolute Pressure (kPa)
#define PID_1_RPM										0x0C	// RPM
#define PID_1_SPEED										0x0D	// Speed (km/h)
#define PID_1_TIMING_ADVANCE							0x0E	// Timing Advance (°)
#define PID_1_INTAKE_TEMP								0x0F	// Intake Air Temperature (°C)
#define PID_1_MAF_FLOW									0x10	// MAF Flow Rate (grams/sec)
#define PID_1_THROTTLE									0x11	// Throttle Position (%)
#define PID_1_COMMAND_SECONDARY_AIR_STATUS				0x12	// Commanded Secondary Air Status (bit encoded)
#define PID_1_OXYGEN_SENSORS_PRESENT_BANK_2				0x13	// Oxygen Sensors Present 2 Banks (bit encoded)
#define PID_1_OXYGEN_SENSOR_1A_VOLTAGE					0x14	// Oxygen Sensor 1A Voltage (V, %)
#define PID_1_OXYGEN_SENSOR_1A_VOLTAGE					0x15	// Oxygen Sensor 2A Voltage (V, %)
#define PID_1_OXYGEN_SENSOR_1A_VOLTAGE					0x16	// Oxygen Sensor 3A Voltage (V, %)
#define PID_1_OXYGEN_SENSOR_1A_VOLTAGE					0x17	// Oxygen Sensor 4A Voltage (V, %)
#define PID_1_OXYGEN_SENSOR_1A_VOLTAGE					0x18	// Oxygen Sensor 5A Voltage (V, %)
#define PID_1_OXYGEN_SENSOR_1A_VOLTAGE					0x19	// Oxygen Sensor 6A Voltage (V, %)
#define PID_1_OXYGEN_SENSOR_1A_VOLTAGE					0x1A	// Oxygen Sensor 7A Voltage (V, %)
#define PID_1_OXYGEN_SENSOR_1A_VOLTAGE					0x1B	// Oxygen Sensor 8A Voltage (V, %)
#define PID_1_OBD_STANDARDS								0x1C	// OBD Standards This Vehicle Conforms To (bit encoded)
#define PID_1_OXYGEN_SENSORS_PRESENT_BANK_4				0x1D	// Oxygen Sensors Present 4 Banks (bit encoded)
#define PID_1_AUXILIARY_INPUT_STATUS					0x1E	// Auxiliary Input Status (bit encoded)
#define PID_1_RUNTIME_SINCE_ENGINE_START				0x1F	// Run Time Since Engine Start (seconds)
#define PID_1_PIDS_SUPPORTED_21_40						0x20	// PID's supported 0x21 - 0x40
#define PID_1_DISTANCE_WITH_MIL							0x21 	// Distance Traveled With MIL On (km)
#define PID_1_FUEL_RAIL_PRESSURE						0x22	// Fuel Rail Pressure (kPa)
#define PID_1_FUEL_RAIL_GAUGE_PRESSURE					0x23	// Fuel Rail Gauge Pressure (kPa)
#define PID_1_OXYGEN_SENSOR_1B_VOLTAGE					0x24	// Oxygen Sensor 1B Voltage (ratio, voltage)
#define PID_1_OXYGEN_SENSOR_2B_VOLTAGE					0x25	// Oxygen Sensor 2B Voltage (ratio, voltage)
#define PID_1_OXYGEN_SENSOR_3B_VOLTAGE					0x26	// Oxygen Sensor 3B Voltage (ratio, voltage)
#define PID_1_OXYGEN_SENSOR_4B_VOLTAGE					0x27	// Oxygen Sensor 4B Voltage (ratio, voltage)
#define PID_1_OXYGEN_SENSOR_5B_VOLTAGE					0x28	// Oxygen Sensor 5B Voltage (ratio, voltage)
#define PID_1_OXYGEN_SENSOR_6B_VOLTAGE					0x29	// Oxygen Sensor 6B Voltage (ratio, voltage)
#define PID_1_OXYGEN_SENSOR_7B_VOLTAGE					0x2A	// Oxygen Sensor 7B Voltage (ratio, voltage)
#define PID_1_OXYGEN_SENSOR_8B_VOLTAGE					0x2B	// Oxygen Sensor 8B Voltage ((ratio, voltage)
#define PID_1_COMMANDED_EGR								0x2C	// Commanded EGR (%)
#define PID_1_EGR_ERROR									0x2D	// EGR Error (%)
#define PID_1_COMMANDED_EVAPORATIVE_PURGE				0x2E	// Commanded Evaporative Purge (%)
#define PID_1_FUEL_LEVEL								0x2F	// Fuel Tank Level Input (%)
#define PID_1_WARMS_UPS									0x30	// Warm-ups Since Codes Cleared (count)
#define PID_1_DISTANCE									0x31	// Distance Traveled Since Codes Cleared (km)
#define PID_1_EVAP_SYS_VAPOR_PRESSURE					0x32	// Evap System Vapor Pressure (Pa)
#define PID_1_BAROMETRIC								0x33	// Absolute Barometric Pressure (kPa)
#define PID_1_OXYGEN_SENSOR_1C_VOLTAGE					0x34	// Oxygen Sensor 1C Voltage (current)
#define PID_1_OXYGEN_SENSOR_2C_VOLTAGE					0x35	// Oxygen Sensor 2C Voltage (current)
#define PID_1_OXYGEN_SENSOR_3C_VOLTAGE					0x36	// Oxygen Sensor 3C Voltage (current)
#define PID_1_OXYGEN_SENSOR_4C_VOLTAGE					0x37	// Oxygen Sensor 4C Voltage (current)
#define PID_1_OXYGEN_SENSOR_5C_VOLTAGE					0x38	// Oxygen Sensor 5C Voltage (current)
#define PID_1_OXYGEN_SENSOR_6C_VOLTAGE					0x39	// Oxygen Sensor 6C Voltage (current)
#define PID_1_OXYGEN_SENSOR_7C_VOLTAGE					0x3A	// Oxygen Sensor 7C Voltage (current)
#define PID_1_OXYGEN_SENSOR_8C_VOLTAGE					0x3B	// Oxygen Sensor 8C Voltage (current)
#define PID_1_CATALYST_TEMP_BANK1_SENSOR1				0x3C	// Catalyst Temperature Bank 1 Sensor 1 (°C)
#define PID_1_CATALYST_TEMP_BANK2_SENSOR1				0x3D	// Catalyst Temperature Bank 2 Sensor 1 (°C)
#define PID_1_CATALYST_TEMP_BANK1_SENSOR2				0x3E	// Catalyst Temperature Bank 1 Sensor 2 (°C)
#define PID_1_CATALYST_TEMP_BANK2_SENSOR2				0x3F	// Catalyst Temperature Bank 2 Sensor 2 (°C)
#define PID_1_PIDS_SUPPORTED_41_60						0x40	// PID's supported 0x41 - 0x60
#define PID_1_MONITOR_STATUS_THIS_DRIVE_CYCLE			0x41	// Monitor status this drive cycle (bit encoded)
#define PID_1_CONTROL_MODULE_VOLTAGE					0x42	// Control module voltage (V)
#define PID_1_ABSOLUTE_ENGINE_LOAD						0x43	// Absolute load value (%)
#define PID_1_AIR_FUEL_EQUIV_RATIO						0x44	// Fuel/Air commanded equivalence ratio (lambda)
#define PID_1_RELATIVE_THROTTLE_POSITION				0x45	// Relative throttle position (%)
#define PID_1_AMBIENT_TEMPERATURE						0x46	// Ambient air temp (°C)
#define PID_1_ABSOLUTE_THROTTLE_POSITION_B				0x47	// Absolute throttle position B (%)
#define PID_1_ABSOLUTE_THROTTLE_POSITION_C				0x48	// Absolute throttle position C (%)
#define PID_1_ACC_PEDAL_POSITION_D						0x49	// Accelerator pedal position D (%)
#define PID_1_ACC_PEDAL_POSITION_E						0x4A	// Accelerator pedal position E (%)
#define PID_1_ACC_PEDAL_POSITION_F						0x4B	// Accelerator pedal position F (%)
#define PID_1_COMMANDED_THROTTLE_ACTUATOR				0x4C	// Commanded throttle actuator (%)
#define PID_1_TIME_WITH_MIL								0x4D	// Time run with MIL on (min)
#define PID_1_TIME_SINCE_CODES_CLEARED					0x4E	// Time since trouble codes cleared (min)
#define PID_1_MAX_VALUES_FOR_SENSORS					0x4F	// Max values for sensors (ratio, V, mA, kPa)
#define PID_1_MAX_VALUE_FOR_AIR_FLOW_SENSOR				0x50	// Maximum value for air flow rate from mass air flow sensor (g/s)
#define PID_1_FUEL_TYPE									0x51	// Fuel Type (bit encoded)
#define PID_1_ETHANOL_FUEL								0x52	// Ethanol fuel (%)
#define PID_1_ABSOLUTE_EVAP_SYSTEM_PRESSURE				0x53	// Absolute evap system pressure (kPa)
#define PID_1_EVAP_SYSTEM_VAPOR_PRESSURE				0x54	// Evap system vapor pressure (Pa)
#define PID_1_SHORT_TERM_SEC_OXYGEN_SENSOR_TRIM_AB1_BB3	0x55	// Short term secondary oxygen sensor trim, A: bank 1, B: bank 3 (%)
#define PID_1_LONG_TERM_PRI_OXYGEN_SENSOR_TRIM_AB1_BB3	0x56	// Long term primary oxygen sensor trim, A: bank 1, B: bank 3 (%)
#define PID_1_SHORT_TERM_SEC_OXYGEN_SENSOR_TRIM_AB2_BB4	0x57	// Short term secondary oxygen sensor trim, A: bank 1, B: bank 3 (%)
#define PID_1_LONG_TERM_SEC_OXYGEN_SENSOR_TRIM_AB2_BB4	0x58	// Long term secondary oxygen sensor trim, A: bank 1, B: bank 3 (%)
#define PID_1_FUEL_RAIL_PRESSURE						0x59	// Fuel rail absolute pressure (kPa)
#define PID_1_RELATIVE_ACCELERATOR_PEDAL_POSITION		0x5A	// Relative accelerator pedal position (%)
#define PID_1_HYBRID_BATTERY_PERCENTAGE					0x5B	// Hybrid battery pack remaining life (%)
#define PID_1_ENGINE_OIL_TEMP							0x5C	// Engine oil temperature (°C)
#define PID_1_FUEL_INJECTION_TIMING						0x5D	// Fuel injection timing (°)
#define PID_1_ENGINE_FUEL_RATE							0x5E	// Engine fuel rate (L/h)
#define PID_1_EMISSIONS_REQUIREMENTS					0x5F	// Emission requirements to which vehicle is designed (bit encoded)
#define PID_1_PIDS_SUPPORTED_61_80						0x60	// PID's supported 0x61 - 0x80
#define PID_1_ENGINE_TORQUE_DEMANDED					0x61	// Driver's demand engine - percent torque (%)
#define PID_1_ENGINE_TORQUE_PERCENTAGE					0x62	// Actual engine - percent torque (%)
#define PID_1_ENGINE_REF_TORQUE							0x63	// Engine reference torque (Nm)
#define PID_1_ENGINE_TORQUE_PERCENTAGE_DATA				0x64	// Engine percent torque data 
#define PID_1_AUX_INPUT_OUTPUT_SUPPORTED				0x65	// Auxiliary input / output supported (bit encoded)
#define PID_1_MASS_AIR_FLOW_SENSOR						0x66	// Mass air flow sensor (g/s)
#define PID_1_ENGINE_COOLANT_TEMPERATURE				0x67	// Engine coolant temperature (°C)
#define PID_1_INTAKE_AIR_TEMPERATURE_SENSOR				0x68	// Intake air temperature sensor (°C)
#define PID_1_EGR_ACTUAL_COMMANDED_ERROR				0x69	// Actual EGR, Commanded EGR, and EGR Error
#define PID_1_COMMANDED_DIESEL_INTAKE_AIR_FLOW_CONTROL	0x6A	// Commanded Diesel intake air flow control and relative intake air flow position
#define PID_1_EXHAUST_GAS_RECIRCULATION_TEMPERATURE		0x6B	// Exhaust gas recirculation temperature
#define PID_1_COMMANDED_THROTTLE_ACTUATOR_CONTROL		0x6C	// Commanded throttle actuator control and relative throttle position 
#define PID_1_FUEL_PRESSURE_CONTROL_SYSTEM				0x6D	// Fuel pressure control system
#define PID_1_INJECTION_PRESSURE_CONTROL_SYSTEM			0x6E	// Injection pressure control system
#define PID_1_TURBOCHARGER_COMPRESSOR_INLET_PRESSURE	0x6F	// Turbocharger compressor inlet pressure
#define PID_1_BOOST_PRESSURE_CONTROL					0x70	// Boost pressure control
#define PID_1_VARIABLE_GEOMETRY_TURBO_CONTROL			0x71	// Variable Geometry turbo (VGT) control
#define PID_1_WASTEGATE_CONTROL							0x72	// Wastegate control
#define PID_1_EXHAUST_PRESSURE							0x73	// Exhaust pressure
#define PID_1_TURBOCHARGER_RPM							0x74	// Turbocharder RPM
#define PID_1_TURBOCHARGER_TEMPERATURE1					0x75	// Turbocharder temperature
#define PID_1_TURBOCHARGER_TEMPERATURE2					0x76	// Turbocharder temperature
#define PID_1_CHARGE_AIR_COOLER_TEMPERATURE				0x77	// Charge air cooler temperature (CACT)
#define PID_1_EXHAUST_GAS_TEMPERATURE_BANK_1			0x78	// Exhaust Gas temperature (EGT) Bank 1
#define PID_1_EXHAUST_GAS_TEMPERATURE_BANK_2			0x79	// Exhaust Gas temperature (EGT) Bank 2
#define PID_1_DIESEL_PARTICULATE_FILTER_DIFF_PRESSURE	0x7A	// Diesel particulate filter (DPF) differential pressure
#define PID_1_DIESEL_PARTICULATE_FILTER					0x7B	// Diesel particulate filter (DPF)
#define PID_1_DIESEL_PARTICULATE_FILTER_TEMPERATURE		0x7C	// Diesel particulate filter (DPF) temperature
#define PID_1_NOX_NTE_CONTROL_AREA_STATUS_1				0x7D	// NOx NTE (Not-To-Exceed) control area status
#define PID_1_NOX_NTE_CONTROL_AREA_STATUS_2				0x7E	// NOx NTE (Not-To-Exceed) control area status
#define PID_1_ENGINE_RUN_TIME							0x7F	// Engine run time
#define PID_1_PIDS_SUPPORTED_81_A0						0x80	// PID's supported 0x81 - 0xA0
#define PID_1_ENGINE_RUNTIME_AECD_1						0x81	// Engine run time for Auxiliary Emissions Control Device(AECD)
#define PID_1_ENGINE_RUNTIME_AECD_2						0x82	// Engine run time for Auxiliary Emissions Control Device(AECD)
#define PID_1_NOX_SENSOR								0x83	// NOx sensor
#define PID_1_MANIFOLD_SURFACE_TEMPERATURE				0x84	// Manifold surface temperature
#define PID_1_NOX_REAGENT_SYSTEM						0x85	// NOx reagent system
#define PID_1_PM_SENSOR									0x86	// Particulate matter (PM) sensor
#define PID_1_INTAKE_MANIFOLD_ABSOLUTE_PRESSURE			0x87	// Intake manifold absolute pressure
#define PID_1_SCR_INDUCE_SYSTEM							0x88	// SCR Induce System
#define PID_1_RUN_TIME_FOR_AECD_11_15					0x89	// Run Time for AECD #11-#15
#define PID_1_RUN_TIME_FOR_AECD_16_20					0x8A	// Run Time for AECD #16-#20
#define PID_1_DIESEL_AFTERTREATMENT						0x8B	// Diesel Aftertreatment
#define PID_1_O2_WIDERANGE_SENSOR						0x8C	// O2 Sensor (Wide Range)
#define PID_1_THROTTLE_POSITION_G						0x8D	// Throttle Position G
#define PID_1_ENGINE_FRICTION_PERCENT_TORQUE			0x8E	// Engine Friction - Percent Torque
#define PID_1_PM_SENSOR_BANK_1_2						0x8F	// PM Sensor Bank 1 & 2
#define PID_1_WWH_OBD_VEHICLE_OBD_SYSTEM_INFORMATION_1	0x90	// WWH-OBD Vehicle OBD System Information
#define PID_1_WWH_OBD_VEHICLE_OBD_SYSTEM_INFORMATION_2	0x91	// WWH-OBD Vehicle OBD System Information
#define PID_1_FUEL_SYSTEM_CONTROL						0x92	// Fuel System Control
#define PID_1_WWH_OBD_VEHICLE_OBD_COUNTERS_SUPPORT		0x93	// WWH-OBD Vehicle OBD Counters support
#define PID_1_NOX_WARNING_AND_INDUCEMENT_SYSTEM			0x94	// NOx Warning And Inducement System
#define PID_1_95										0x95	// Reserved
#define PID_1_96										0x96	// Reserved
#define PID_1_97										0x97	// Reserved
#define PID_1_EXHAUST_GAS_TEMPERATURE_SENSOR_1			0x98	// Exhaust Gas Temperature Sensor
#define PID_1_EXHAUST_GAS_TEMPERATURE_SENSOR_2			0x99	// Exhaust Gas Temperature Sensor
#define PID_1_HYBRID_EV_VEHICLE_SYSTEM_DATA				0x9A	// Hybrid/EV Vehicle System Data, Battery, Voltage
#define PID_1_DIESEL_EXHAUST_FLUID_SENSOR_DATA			0x9B	// Diesel Exhaust Fluid Sensor Data
#define PID_1_O2_SENSOR_DATA							0x9C	// O2 Sensor Data
#define PID_1_ENGINE_FUEL_RATE							0x9D	// Engine Fuel Rate
#define PID_1_ENGINE_EXHAUST_FLOW_RATE					0x9E	// Engine Exhaust Flow Rate
#define PID_1_FUEL_SYSTEM_PERCENTAGE_USE				0x9F	// Fuel System Percentage Use
#define PID_1_PIDS_SUPPORTED_A1_C0						0xA0	// PID's supported 0xA1 - 0xC0
#define PID_1_NOX_SENSOR_CORRECTED_DATA					0xA1	// NOx Sensor Corrected Data
#define PID_1_CYLINDER_FUEL_RATE						0xA2	// Cylinder Fuel Rate 
#define PID_1_EVAP_SYSTEM_VAPOR_PRESSURE				0xA3	// Evap System Vapor Pressure
#define PID_1_TRANSMISSION_ACTUAL_GEAR					0xA4	// Transmission Actual Gear
#define PID_1_COMMANDED_DIESEL_EXHAUST_FLUID_DOSING		0xA5	// Commanded Diesel Exhaust Fluid Dosing
#define PID_1_ODOMETER									0xA6	// Odometer (km)
#define PID_1_NOX_SENSOR_CONCENTRATION_3_4				0xA7	// NOx Sensor Concentration Sensors 3 and 4
#define PID_1_NOX_SENSOR_CORRECTED_CONCENTRATION_3_4	0xA8	// NOx Sensor Corrected Concentration Sensors 3 and 4
#define PID_1_ABS_DISABLE_SWITCH_STATE					0xA9	// ABS Disable Switch State
#define PID_1_AA										0xAA	// Reserved
#define PID_1_AB										0xAB	// Reserved
#define PID_1_AC										0xAC	// Reserved
#define PID_1_AD										0xAD	// Reserved
#define PID_1_AE										0xAE	// Reserved
#define PID_1_AF										0xAF	// Reserved
#define PID_1_B0										0xB0	// Reserved
#define PID_1_B1										0xB1	// Reserved
#define PID_1_B2										0xB2	// Reserved
#define PID_1_B3										0xB3	// Reserved
#define PID_1_B4										0xB4	// Reserved
#define PID_1_B5										0xB5	// Reserved
#define PID_1_B6										0xB6	// Reserved
#define PID_1_B7										0xB7	// Reserved
#define PID_1_B8										0xB8	// Reserved
#define PID_1_B9										0xB9	// Reserved
#define PID_1_BA										0xBA	// Reserved
#define PID_1_BB										0xBB	// Reserved
#define PID_1_BC										0xBC	// Reserved
#define PID_1_BD										0xBD	// Reserved
#define PID_1_BE										0xBE	// Reserved
#define PID_1_BF										0xBF	// Reserved
#define PID_1_PIDS_SUPPORTED_C1_E0						0xC0	// PID's supported 0xC1 - 0xE0
#define PID_1_C1										0xC1	// Reserved
#define PID_1_C2										0xC2	// Reserved
#define PID_1_FUEL_LEVEL_INPUT_A_B						0xC3	// Fuel Level Input A/B
#define PID_1_EXHAUST_PARTICULATE_CONTROL_SYSTEM_DIAG	0xC4	// Exhaust Particulate Control System Diagnostic Time/Count
																// 0xB4: Engine Idle Request
																// 0xB5: Engine Stop Request
#define PID_1_FUEL_PRESSURE_A_B							0xC5	// Fuel Pressure A and B
#define PID_1_											0xC6	// Byte 1 - Particulate control - driver inducement system status
																// Byte 2,3 - Removal or block of the particulate aftertreatment system counter
																// Byte 4,5 - Liquid regent injection system (e.g. fuel-borne catalyst) failure counter
																// Byte 6,7 - Malfunction of Particulate control monitoring system counter
#define PID_1_DISTANCE_SINCE_REFLASH					0xC7	// Distance Since Reflash or Module Replacement
#define PID_1_NOX_PCD_DIAGNOSTICS_CONTROL				0xC8	// NOx Control Diagnostic (NCD) and Particulate Control Diagnostic (PCD) Warning Lamp status

/* Mode 9 - Request vehicle information PID's */
#define PID_9_PIDS_SUPPORTED_01_20						0x00	// Service 9 supported PIDs 0x01 to 0x20
#define PID_9_VIN_MESSAGE_COUNT							0x01	// VIN (Vehicle Identification Number) Message Count
#define PID_9_VIN										0x02	// VIN (Vehicle Identification Number)
#define PID_9_CALIBRATION_ID_MESSAGE_COUNT				0x03	// Calibration ID message count
#define PID_9_CALIBRATION_ID							0x04	// Calibration ID
#define PID_9_CVN_MESSAGE_COUNT							0x05	// Calibration Verification Numbers (CVN) message count
#define PID_9_CVN										0x06	// Calibration Verification Numbers (CVN)
#define PID_9_IN_USE_PERFORMANCE_SPARK_MESSAGE_COUNT	0x07	// In-use performance tracking for spark ignition vehicles message count
#define PID_9_IN_USE_PERFORMANCE_SPARK					0x08	// In-use performance tracking for spark ignition vehicles 
#define PID_9_ECU_NAME_MESSAGE_COUNT					0x09	// ECU name message count
#define PID_9_ECU_NAME									0x0A	// ECU name
#define PID_9_IN_USE_PERFORMANCE_COMPRESSION			0x0B	// In-use performance tracking for compression ignition vehicles
