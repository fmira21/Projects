;* ************************************************************************** */
;*                                                                            */
;*                                                        :::      ::::::::   */
;*   main.c                                             :+:      :+:    :+:   */
;*                                                    +:+ +:+         +:+     */
;*   By: fmira <marvin@42.fr>                       +#+  +:+       +#+        */
;*                                                +#+#+#+#+#+   +#+           */
;*   Created: 2021/05/06 10:15:52 by fmira             #+#    #+#             */
;*   Updated: 2021/05/06 10:15:52 by fmira            ###   ########.fr       */
;*                                                                            */
;* ************************************************************************** */

global _ft_strlen
section .text
_ft_strlen:
    xor     rax, rax
    length:
        cmp     byte[rax+rdi], 0    ; Look for a null-terminator in the RDI string
        je 		exit                ; If equal, perform 'exit'
        inc	 	rax                 ; If not equal, increment rax and
        jmp 	length              ; perform 'length'
exit:
	ret
