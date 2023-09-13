/*
 * PARSER.h
 *
 *  Created on: Aug 2, 2023
 *      Author: shady
 */

#ifndef PARSER_PARSER_H_
#define PARSER_PARSER_H_

#define LOW_ADD_MSK 0XFFFF


void Parser_voidParseRecord(u8 *u8RecBuffer);
void ConvertRecieveToRecord(u8* Receive_array,u8* Record_array);

#endif /* PARSER_PARSER_H_ */
