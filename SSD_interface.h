


#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


#define SSD_ONE       1
#define SSD_TWO       2

void display                (u8 data , u8 TIME);
void SSD_SHUTDOWN           (void);
void SSD_initDirections     (void);
void SSD_displayNumber      (u8 desiredNumber,u8 ssdId);
void SSD_displayMultiNumber (u8 desiredNumber);
void SSD_writeHalfPort      (u8 value);

#endif /* SSD_INTERFACE_H_ */
