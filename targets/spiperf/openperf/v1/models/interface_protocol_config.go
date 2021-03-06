// Code generated by go-swagger; DO NOT EDIT.

package models

// This file was generated by the swagger tool.
// Editing this file might prove futile when you re-run the swagger generate command

import (
	"encoding/json"

	"github.com/go-openapi/errors"
	strfmt "github.com/go-openapi/strfmt"
	"github.com/go-openapi/swag"
	"github.com/go-openapi/validate"
)

// InterfaceProtocolConfig Network interface protocol configuration
// swagger:model InterfaceProtocolConfig
type InterfaceProtocolConfig struct {

	// eth
	Eth *InterfaceProtocolConfigEth `json:"eth,omitempty"`

	// ipv4
	IPV4 *InterfaceProtocolConfigIPV4 `json:"ipv4,omitempty"`
}

// Validate validates this interface protocol config
func (m *InterfaceProtocolConfig) Validate(formats strfmt.Registry) error {
	var res []error

	if err := m.validateEth(formats); err != nil {
		res = append(res, err)
	}

	if err := m.validateIPV4(formats); err != nil {
		res = append(res, err)
	}

	if len(res) > 0 {
		return errors.CompositeValidationError(res...)
	}
	return nil
}

func (m *InterfaceProtocolConfig) validateEth(formats strfmt.Registry) error {

	if swag.IsZero(m.Eth) { // not required
		return nil
	}

	if m.Eth != nil {
		if err := m.Eth.Validate(formats); err != nil {
			if ve, ok := err.(*errors.Validation); ok {
				return ve.ValidateName("eth")
			}
			return err
		}
	}

	return nil
}

func (m *InterfaceProtocolConfig) validateIPV4(formats strfmt.Registry) error {

	if swag.IsZero(m.IPV4) { // not required
		return nil
	}

	if m.IPV4 != nil {
		if err := m.IPV4.Validate(formats); err != nil {
			if ve, ok := err.(*errors.Validation); ok {
				return ve.ValidateName("ipv4")
			}
			return err
		}
	}

	return nil
}

// MarshalBinary interface implementation
func (m *InterfaceProtocolConfig) MarshalBinary() ([]byte, error) {
	if m == nil {
		return nil, nil
	}
	return swag.WriteJSON(m)
}

// UnmarshalBinary interface implementation
func (m *InterfaceProtocolConfig) UnmarshalBinary(b []byte) error {
	var res InterfaceProtocolConfig
	if err := swag.ReadJSON(b, &res); err != nil {
		return err
	}
	*m = res
	return nil
}

// InterfaceProtocolConfigEth Ethernet protocol configuration
// swagger:model InterfaceProtocolConfigEth
type InterfaceProtocolConfigEth struct {

	// MAC address
	// Required: true
	MacAddress *string `json:"mac_address"`
}

// Validate validates this interface protocol config eth
func (m *InterfaceProtocolConfigEth) Validate(formats strfmt.Registry) error {
	var res []error

	if err := m.validateMacAddress(formats); err != nil {
		res = append(res, err)
	}

	if len(res) > 0 {
		return errors.CompositeValidationError(res...)
	}
	return nil
}

func (m *InterfaceProtocolConfigEth) validateMacAddress(formats strfmt.Registry) error {

	if err := validate.Required("eth"+"."+"mac_address", "body", m.MacAddress); err != nil {
		return err
	}

	return nil
}

// MarshalBinary interface implementation
func (m *InterfaceProtocolConfigEth) MarshalBinary() ([]byte, error) {
	if m == nil {
		return nil, nil
	}
	return swag.WriteJSON(m)
}

// UnmarshalBinary interface implementation
func (m *InterfaceProtocolConfigEth) UnmarshalBinary(b []byte) error {
	var res InterfaceProtocolConfigEth
	if err := swag.ReadJSON(b, &res); err != nil {
		return err
	}
	*m = res
	return nil
}

// InterfaceProtocolConfigIPV4 IPv4 protocol configuration
// swagger:model InterfaceProtocolConfigIPV4
type InterfaceProtocolConfigIPV4 struct {

	// dhcp
	Dhcp *InterfaceProtocolConfigIPV4Dhcp `json:"dhcp,omitempty"`

	// Configuration method
	// Required: true
	// Enum: [static dhcp]
	Method *string `json:"method"`

	// static
	Static *InterfaceProtocolConfigIPV4Static `json:"static,omitempty"`
}

// Validate validates this interface protocol config IP v4
func (m *InterfaceProtocolConfigIPV4) Validate(formats strfmt.Registry) error {
	var res []error

	if err := m.validateDhcp(formats); err != nil {
		res = append(res, err)
	}

	if err := m.validateMethod(formats); err != nil {
		res = append(res, err)
	}

	if err := m.validateStatic(formats); err != nil {
		res = append(res, err)
	}

	if len(res) > 0 {
		return errors.CompositeValidationError(res...)
	}
	return nil
}

func (m *InterfaceProtocolConfigIPV4) validateDhcp(formats strfmt.Registry) error {

	if swag.IsZero(m.Dhcp) { // not required
		return nil
	}

	if m.Dhcp != nil {
		if err := m.Dhcp.Validate(formats); err != nil {
			if ve, ok := err.(*errors.Validation); ok {
				return ve.ValidateName("ipv4" + "." + "dhcp")
			}
			return err
		}
	}

	return nil
}

var interfaceProtocolConfigIpV4TypeMethodPropEnum []interface{}

func init() {
	var res []string
	if err := json.Unmarshal([]byte(`["static","dhcp"]`), &res); err != nil {
		panic(err)
	}
	for _, v := range res {
		interfaceProtocolConfigIpV4TypeMethodPropEnum = append(interfaceProtocolConfigIpV4TypeMethodPropEnum, v)
	}
}

const (

	// InterfaceProtocolConfigIPV4MethodStatic captures enum value "static"
	InterfaceProtocolConfigIPV4MethodStatic string = "static"

	// InterfaceProtocolConfigIPV4MethodDhcp captures enum value "dhcp"
	InterfaceProtocolConfigIPV4MethodDhcp string = "dhcp"
)

// prop value enum
func (m *InterfaceProtocolConfigIPV4) validateMethodEnum(path, location string, value string) error {
	if err := validate.Enum(path, location, value, interfaceProtocolConfigIpV4TypeMethodPropEnum); err != nil {
		return err
	}
	return nil
}

func (m *InterfaceProtocolConfigIPV4) validateMethod(formats strfmt.Registry) error {

	if err := validate.Required("ipv4"+"."+"method", "body", m.Method); err != nil {
		return err
	}

	// value enum
	if err := m.validateMethodEnum("ipv4"+"."+"method", "body", *m.Method); err != nil {
		return err
	}

	return nil
}

func (m *InterfaceProtocolConfigIPV4) validateStatic(formats strfmt.Registry) error {

	if swag.IsZero(m.Static) { // not required
		return nil
	}

	if m.Static != nil {
		if err := m.Static.Validate(formats); err != nil {
			if ve, ok := err.(*errors.Validation); ok {
				return ve.ValidateName("ipv4" + "." + "static")
			}
			return err
		}
	}

	return nil
}

// MarshalBinary interface implementation
func (m *InterfaceProtocolConfigIPV4) MarshalBinary() ([]byte, error) {
	if m == nil {
		return nil, nil
	}
	return swag.WriteJSON(m)
}

// UnmarshalBinary interface implementation
func (m *InterfaceProtocolConfigIPV4) UnmarshalBinary(b []byte) error {
	var res InterfaceProtocolConfigIPV4
	if err := swag.ReadJSON(b, &res); err != nil {
		return err
	}
	*m = res
	return nil
}

// InterfaceProtocolConfigIPV4Dhcp DHCP configuration parameters
// swagger:model InterfaceProtocolConfigIPV4Dhcp
type InterfaceProtocolConfigIPV4Dhcp struct {

	// Client identifier
	Client string `json:"client,omitempty"`

	// Hostname to be requested
	Hostname string `json:"hostname,omitempty"`
}

// Validate validates this interface protocol config IP v4 dhcp
func (m *InterfaceProtocolConfigIPV4Dhcp) Validate(formats strfmt.Registry) error {
	return nil
}

// MarshalBinary interface implementation
func (m *InterfaceProtocolConfigIPV4Dhcp) MarshalBinary() ([]byte, error) {
	if m == nil {
		return nil, nil
	}
	return swag.WriteJSON(m)
}

// UnmarshalBinary interface implementation
func (m *InterfaceProtocolConfigIPV4Dhcp) UnmarshalBinary(b []byte) error {
	var res InterfaceProtocolConfigIPV4Dhcp
	if err := swag.ReadJSON(b, &res); err != nil {
		return err
	}
	*m = res
	return nil
}

// InterfaceProtocolConfigIPV4Static Static configuration parameters
// swagger:model InterfaceProtocolConfigIPV4Static
type InterfaceProtocolConfigIPV4Static struct {

	// IP address
	// Required: true
	Address *string `json:"address"`

	// Default gateway
	Gateway string `json:"gateway,omitempty"`

	// Prefix length
	// Required: true
	PrefixLength *int32 `json:"prefix_length"`
}

// Validate validates this interface protocol config IP v4 static
func (m *InterfaceProtocolConfigIPV4Static) Validate(formats strfmt.Registry) error {
	var res []error

	if err := m.validateAddress(formats); err != nil {
		res = append(res, err)
	}

	if err := m.validatePrefixLength(formats); err != nil {
		res = append(res, err)
	}

	if len(res) > 0 {
		return errors.CompositeValidationError(res...)
	}
	return nil
}

func (m *InterfaceProtocolConfigIPV4Static) validateAddress(formats strfmt.Registry) error {

	if err := validate.Required("ipv4"+"."+"static"+"."+"address", "body", m.Address); err != nil {
		return err
	}

	return nil
}

func (m *InterfaceProtocolConfigIPV4Static) validatePrefixLength(formats strfmt.Registry) error {

	if err := validate.Required("ipv4"+"."+"static"+"."+"prefix_length", "body", m.PrefixLength); err != nil {
		return err
	}

	return nil
}

// MarshalBinary interface implementation
func (m *InterfaceProtocolConfigIPV4Static) MarshalBinary() ([]byte, error) {
	if m == nil {
		return nil, nil
	}
	return swag.WriteJSON(m)
}

// UnmarshalBinary interface implementation
func (m *InterfaceProtocolConfigIPV4Static) UnmarshalBinary(b []byte) error {
	var res InterfaceProtocolConfigIPV4Static
	if err := swag.ReadJSON(b, &res); err != nil {
		return err
	}
	*m = res
	return nil
}
